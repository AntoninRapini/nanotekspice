//
// Created by romain on 01/03/2018.
//

#ifndef CPP_NANOTEKSPICE_HEADER_H
#define CPP_NANOTEKSPICE_HEADER_H

#include "ComponentFactory.hpp"
#include "NtsManager.hpp"

#include <regex>
#include <unordered_map>
#include <fstream>

namespace nts {
    class Parser {

    public:
        Parser(ComponentFactory &factory, NtsManager &manager, std::string const file)
                : _factory(&factory),
                  _chipsets(manager.getComponents()),
                  _unused(), _file(file),
                  _state(COMMENTS),
                  _stream(file) {};

        ~Parser() = default;

        Parser(Parser const &) = delete;

        Parser(Parser &) = delete;

        Parser &operator=(Parser const &) = delete;

        Parser &operator=(Parser &) = delete;

        /**
         * Perform the parsing of the file field
         *
         * @throws  ParsingError if the file cant be parsed
         */
        void run();

        bool successed() const;

    private:
        static char constexpr CONFIG_KW_CHIPSETS[] = ".chipsets:";
        static char constexpr CONFIG_KW_LINKS[] = ".links:";

        static std::regex const REGEX_COMMENTS;
        static std::regex const REGEX_CHIPSETS;
        static std::regex const REGEX_LINKS;

        bool parse_comments(std::smatch &matcher, std::string &line) const;

        bool parse_chipsets(std::smatch &matcher, std::string &line);

        bool parse_links(std::smatch &matcher, std::string &line);

        void parse_error(std::string error);

        size_t parse_uint(std::string string) const;

        enum ParserFunc {
            COMMENTS,
            CHIPSETS,
            LINKS,
            SUCCESS
        };

        ComponentFactory *_factory;
        std::map<std::string, std::unique_ptr<IComponent>> &_chipsets;
        std::unordered_map<std::string, IComponent *> _unused;
        std::string const _file;
        ParserFunc _state;
        std::ifstream _stream;
    };
}

#endif //CPP_NANOTEKSPICE_HEADER_H
