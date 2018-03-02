//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef UNTITLED3_CONSOLEANALYSER_H
#define UNTITLED3_CONSOLEANALYSER_H

#include <cstddef>
#include "Parser.hpp"
#include "NtsManager.hpp"

namespace nts {
    class ConsoleAnalyser {
    public:
        ConsoleAnalyser(Parser &parser, NtsManager &manager, std::size_t argc, char *args[])
                : _manager(&manager), _init(false), _parsed(false), _parser(&parser), _argc(argc), _args(args) {};
        ~ConsoleAnalyser() = default;
        ConsoleAnalyser(ConsoleAnalyser const &) = delete;
        ConsoleAnalyser(ConsoleAnalyser &) = delete;

        ConsoleAnalyser &operator=(ConsoleAnalyser const &) = delete;
        ConsoleAnalyser &operator=(ConsoleAnalyser &) = delete;

        bool parse_options();
        bool init_analyser();

    private:
        static char constexpr STATEMENT_DELIMITER = ':';

        bool _init;
        bool _parsed;

        bool parse_statement(std::string &line) const;

        Parser * const _parser;
        NtsManager * const _manager;
        size_t const _argc;
        char * const _args[];
    };
}

#endif //UNTITLED3_CONSOLEANALYSER_H
