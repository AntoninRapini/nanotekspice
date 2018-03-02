//
// Created by romain on 01/03/2018.
//

#ifndef CPP_NANOTEKSPICE_HEADER_H
#define CPP_NANOTEKSPICE_HEADER_H

#include "ComponentFactory.hpp"

#include <regex>

namespace nts
{
    class Parser
    {

    public:
        Parser(ComponentFactory &factory, std::string const &file)
                : _factory(&factory), _file(file), _state(COMMENTS), _chipsets() {};
        ~Parser() = default;
        Parser(Parser const &) = delete;
        Parser(Parser &) = delete;

        Parser &operator=(Parser const &) = delete;
        Parser &operator=(Parser &) = delete;

        /**
         * Perform the parsing of the file field
         */
        void run();

        /**
         * Get all parsed components indexed by chipset names
         *
         * @return  the map with all parsed components
         * @throws  ParsingError if the file is not parsed yet
         */
        std::map<std::string, std::unique_ptr<IComponent>> &getChipsets();

    private:
        static char constexpr CONFIG_KW_CHIPSETS[] = ".chipsets:";
        static char constexpr CONFIG_KW_LINKS[] = ".links:";

        static std::regex const REGEX_COMMENTS;
        static std::regex const REGEX_CHIPSETS;
        static std::regex const REGEX_LINKS;

        bool parse_comments(std::smatch &matcher, std::string &line) const;
        bool parse_chipsets(std::smatch &matcher, std::string &line);
        bool parse_links(std::smatch &matcher, std::string &line) const;
        size_t parse_uint(std::string string) const;

        enum ParserFunc {
            COMMENTS,
            CHIPSETS,
            LINKS,
            SUCCESS
        };

        ComponentFactory *_factory;
        std::string const _file;
        ParserFunc _state;
        std::map<std::string, std::unique_ptr<IComponent>> _chipsets;
    };
}

#endif //CPP_NANOTEKSPICE_HEADER_H
