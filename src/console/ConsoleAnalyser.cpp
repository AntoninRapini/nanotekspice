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
    char constexpr ConsoleAnalyser::COMMAND_EXIT[];
    char constexpr ConsoleAnalyser::COMMAND_DISPLAY[];
    char constexpr ConsoleAnalyser::COMMAND_SIMULATE[];
    char constexpr ConsoleAnalyser::COMMAND_LOOP[];
    char constexpr ConsoleAnalyser::COMMAND_DUMP[];

    bool ConsoleAnalyser::parse_options() {
        if (_parsed)
            return false;

        for (size_t i=2; i < _argc; ++i) {
            std::string opt(_args[i]);
            if (!parse_statement(opt))
                throw ParsingError("Invalid option");
        }

        return (_parsed = true);
    }

    bool ConsoleAnalyser::init_analyser() {
        if (_init)
            return false;
        _init = true;

        display_prompt();
        for(std::string line; std::getline(std::cin, line);) {
            if (line == COMMAND_EXIT)
                break;
            else if (line == COMMAND_DISPLAY)
                _manager->Display();
            else if (line == COMMAND_SIMULATE)
                _manager->Simulate();
            else if (line == COMMAND_LOOP)
                _prompt = false;
            else if (line == COMMAND_DUMP)
                _manager->Dump();
            else if (!parse_statement(line))
                throw ParsingError("Unknown command");

            display_prompt();
        }

        return true;
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

    void ConsoleAnalyser::display_prompt() const {
        if (!_prompt)
            return;
        std::cout << "> ";
    }
}