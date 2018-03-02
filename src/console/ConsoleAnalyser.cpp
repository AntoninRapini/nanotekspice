//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <Exceptions.hpp>
#include <iostream>
#include "ConsoleAnalyser.hpp"

namespace nts {
    //reference
    char constexpr ConsoleAnalyser::STATEMENT_DELIMITER;

    bool ConsoleAnalyser::parse_options() {
        if (_parsed)
            return false;

        for (int i=1; i < _argc; ++i) {
            std::string opt(_args[i]);
            std::cout << "got " << opt << std::endl;
            parse_statement(opt);
        }

        return (_parsed = true);
    }

    bool ConsoleAnalyser::init_analyser() {
        if (_init)
            return false;

        for(std::string line; std::getline(std::cin, line);) {
            std::cout << "[console] listened " + line << std::endl;
        }

        return (_init = true);
    }

    bool ConsoleAnalyser::parse_statement(std::string &line) const {
        size_t delimiter_pos = line.find(STATEMENT_DELIMITER);

        if (delimiter_pos == std::string::npos)
            return false;

        std::string component = line.substr(0, delimiter_pos);
        line.erase(0, delimiter_pos + 1);
        char state = (char) std::stoi(line);

        Tristate parsed;

        switch(state) {
            case true:
                parsed = TRUE;
                break;
            case false:
                parsed = FALSE;
                break;
            case -true:
                parsed = UNDEFINED;
                break;
            default:
                throw ParsingError("Invalid command statement found");
        }

        _manager->ChangePinValue(component, parsed);
        return true;
    }
}