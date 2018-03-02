//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <Exceptions.hpp>
#include "ConsoleAnalyser.hpp"

namespace nts {
    void ConsoleAnalyser::parse_options() {
        if (_parsed)
            throw ParsingError("Already have parsed program args");



        _parsed = true;
    }

    void ConsoleAnalyser::init_analyser() {
        if (_init)
            throw ParsingError("Already started the console analyser");



        _init = true;
    }
}