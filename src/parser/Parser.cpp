//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "Parser.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include "Exceptions.hpp"

namespace nts {
    //static const references
    char const constexpr Parser::CONFIG_KW_CHIPSETS[];
    char const constexpr Parser::CONFIG_KW_LINKS[];

    //constants init
    std::regex const Parser::REGEX_COMMENTS("^([^#]+)");
    std::regex const Parser::REGEX_CHIPSETS("^(\\S+)\\s+([^\\s(]+)(?:\\(([^\\s]+)\\))?$");
    std::regex const Parser::REGEX_LINKS("^(\\S+):(\\d+)[^\\S]*(\\S+):(\\d+)$");

    void Parser::run() {
        std::ifstream stream(_file);

        if (!stream.is_open())
            throw(ParsingError("Can't open the file " + _file));

        std::smatch matcher;
        std::string line;

        while (std::getline(stream, line)) {
            if (parse_comments(matcher, line))
                continue;

            switch (_state) {
                case COMMENTS:
                    if (line.find(CONFIG_KW_CHIPSETS))
                        throw(ParsingError("Section chipsets not found"));

                    _state = CHIPSETS;
                    break;
                case CHIPSETS:
                    if (!line.find(CONFIG_KW_LINKS))
                        _state = LINKS;
                    else if (!parse_chipsets(matcher, line))
                        throw(ParsingError("Syntax error while parsing chipsets"));
                    break;
                case LINKS:
                    if (!parse_links(matcher, line))
                        throw(ParsingError("Syntax error while parsing links"));
                    break;
            }
        }

        if (_state != LINKS)
            throw ParsingError(("Section links not found"));
    }

    bool Parser::parse_comments(std::smatch &matcher, std::string &line) const {
        if (!std::regex_search(line, matcher, REGEX_COMMENTS))
            return true;

        line = matcher[1];

        return std::all_of(line.begin(), line.end(), isspace); //return true if only whitespaces
    }

    bool Parser::parse_chipsets(std::smatch &matcher, std::string &line) const {
        if (!std::regex_search(line, matcher, REGEX_CHIPSETS))
            return false;

        std::string component = matcher[1];
        std::string name = matcher[2];
        std::string value = matcher[3]; //empty if not specified

        std::cout << "[parser] " << component << " " << name << " " << value << std::endl;
        return true;
    }

    bool Parser::parse_links(std::smatch &matcher, std::string &line) const {
        if (!std::regex_search(line, matcher, REGEX_LINKS))
            return false;

        std::string component_a = matcher[1];
        std::string pin_a = matcher[2];
        std::string component_b = matcher[3];
        std::string pin_b = matcher[4];

        std::cout << "[parser] " << component_a << "<->" << pin_a << " | " << component_b << "<->" << pin_b << std::endl;
        return true;
    }
}