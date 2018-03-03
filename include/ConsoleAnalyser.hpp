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
        ConsoleAnalyser(NtsManager &manager, std::size_t argc, char *args[])
                : _init(false), _parsed(false), _prompt(true), _manager(&manager), _argc(argc), _args(args) {};
        ~ConsoleAnalyser() = default;
        ConsoleAnalyser(ConsoleAnalyser const &) = delete;
        ConsoleAnalyser(ConsoleAnalyser &) = delete;

        ConsoleAnalyser &operator=(ConsoleAnalyser const &) = delete;
        ConsoleAnalyser &operator=(ConsoleAnalyser &) = delete;

        bool parse_options();
        bool init_analyser();

    private:
        static char constexpr STATEMENT_DELIMITER = '=';
        static char constexpr COMMAND_EXIT[] = "exit";
        static char constexpr COMMAND_DISPLAY[] = "display";
        static char constexpr COMMAND_SIMULATE[] = "simulate";
        static char constexpr COMMAND_LOOP[] = "loop";
        static char constexpr COMMAND_DUMP[] = "dump";

        bool parse_statement(std::string &line) const;
        void display_prompt() const;

        bool _init;
        bool _parsed;
        bool _prompt;
        NtsManager * const _manager;
        size_t const _argc;
        char ** _args;
    };
}

#endif //UNTITLED3_CONSOLEANALYSER_H
