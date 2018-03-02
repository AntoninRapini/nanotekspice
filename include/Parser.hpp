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
                : _factory(&factory), _file(file), _state(COMMENTS) {};
        ~Parser() = default;
        Parser(Parser const &) = delete;
        Parser(Parser &) = delete;

        Parser &operator=(Parser const &) = delete;
        Parser &operator=(Parser &) = delete;

        /**
         * Perform the parsing of the file field previously opened
         */
        void run();

    private:
        static char constexpr CONFIG_KW_CHIPSETS[] = ".chipsets:";
        static char constexpr CONFIG_KW_LINKS[] = ".links:";

        static std::regex const REGEX_COMMENTS;
        static std::regex const REGEX_CHIPSETS;
        static std::regex const REGEX_LINKS;

        bool parse_comments(std::smatch &matcher, std::string &line) const;
        bool parse_chipsets(std::smatch &matcher, std::string &line) const;
        bool parse_links(std::smatch &matcher, std::string &line) const;

        enum ParserFunc {
            COMMENTS,
            CHIPSETS,
            LINKS
        };

        ComponentFactory *_factory;
        std::string const _file;
        ParserFunc _state;
    };
}

#endif //CPP_NANOTEKSPICE_HEADER_H
