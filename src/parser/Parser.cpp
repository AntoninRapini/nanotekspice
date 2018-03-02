//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "Parser.hpp"

#include "Exceptions.hpp"
#include <iostream>
#include <fstream>

namespace nts {
    //static const references
    char constexpr Parser::CONFIG_KW_CHIPSETS[];
    char constexpr Parser::CONFIG_KW_LINKS[];

    //constants init
    std::regex const Parser::REGEX_COMMENTS("^([^#]+)");
    std::regex const Parser::REGEX_CHIPSETS("^(\\S+)\\s+([^\\s(]+)(?:\\(([^\\s]+)\\))?$");
    std::regex const Parser::REGEX_LINKS("^(\\S+):(\\d+)[^\\S]*(\\S+):(\\d+)$");

    void Parser::run() {
        std::ifstream stream(_file);

        if (!stream.is_open())
            throw ParsingError("Can't open the file " + _file);

        std::smatch matcher;
        std::string line;

        while (std::getline(stream, line)) {
            if (!parse_comments(matcher, line))
                continue;

            switch (_state) {
                case COMMENTS:
                    if (line.find(CONFIG_KW_CHIPSETS))
                        throw ParsingError("Section chipsets not found");

                    _state = CHIPSETS;
                    break;
                case CHIPSETS:
                    if (!line.find(CONFIG_KW_LINKS))
                        _state = LINKS;
                    else if (!parse_chipsets(matcher, line))
                        throw ParsingError("Syntax error while parsing chipsets");
                    break;
                case LINKS:
                    if (!parse_links(matcher, line))
                        throw ParsingError("Syntax error while parsing links");
                    break;
                default:
                    break;
            }
        }

        if (_state != LINKS)
            throw ParsingError(("Section links not found"));
        _state = SUCCESS;
    }

    bool Parser::parse_comments(std::smatch &matcher, std::string &line) const {
        if (!std::regex_search(line, matcher, REGEX_COMMENTS))
            return false; //empty line

        line = matcher[1];

        return !std::all_of(line.begin(), line.end(), isspace); //return false if only whitespaces
    }

    bool Parser::parse_chipsets(std::smatch &matcher, std::string &line) {
        if (!std::regex_search(line, matcher, REGEX_CHIPSETS))
            return false;

        std::string component = matcher[1];
        std::string name = matcher[2];
        std::string value = matcher[3]; //empty if not specified

        if (_chipsets.find(name) != _chipsets.end())
            throw ParsingError("Found several chipsets with the same name");

        auto chipset = _factory->createComponent(component, name);
        _chipsets[name] = std::move(chipset);
        return true;
    }

    bool Parser::parse_links(std::smatch &matcher, std::string &line) const {
        if (!std::regex_search(line, matcher, REGEX_LINKS))
            return false;

        std::string linked_name = matcher[1];
        std::size_t linked_pin = parse_uint(matcher[2]);
        std::string linker_name = matcher[3];
        std::size_t linker_pin = parse_uint(matcher[4]);

        auto linked = _chipsets.find(linked_name);
        auto linker = _chipsets.find(linker_name);

        if (linked == _chipsets.end() || linker == _chipsets.end())
            throw ParsingError("Undefined reference name to a chipset");

        std::cout << "Tried to link " << linker_name << ":" << linker_pin << " to " << linked_name << ":"<<linked_pin << std::endl;
        linker->second->setLink(linker_pin, *(linked->second.get()), linked_pin);
        return true;
    }

    size_t Parser::parse_uint(std::string string) const {
        size_t uint;
        std::istringstream(string) >> uint;

        return uint;
    }

    bool Parser::successed() const {
        return _state == SUCCESS;
    }
}