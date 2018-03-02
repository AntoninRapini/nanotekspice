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

namespace nts {
    class ConsoleAnalyser {
    public:
        ConsoleAnalyser(Parser &parser, std::size_t argc, char *args[])
                : _init(false), _parsed(false), _parser(&parser), _argc(argc), _args(args) {};
        ~ConsoleAnalyser() = default;
        ConsoleAnalyser(ConsoleAnalyser const &) = delete;
        ConsoleAnalyser(ConsoleAnalyser &) = delete;

        ConsoleAnalyser &operator=(ConsoleAnalyser const &) = delete;
        ConsoleAnalyser &operator=(ConsoleAnalyser &) = delete;

        void parse_options();
        void init_analyser();
    private:
        bool _init;
        bool _parsed;

        Parser * const _parser;
        size_t const _argc;
        char * const _args[];
    };
}

#endif //UNTITLED3_CONSOLEANALYSER_H
