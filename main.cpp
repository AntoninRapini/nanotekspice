//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <NtsManager.hpp>
#include <ConsoleAnalyser.hpp>
#include "C4081.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Parser.hpp"
#include "ComponentFactory.hpp"

int main(int ac, char **args) {
    nts::ComponentFactory factory;
    nts::NtsManager manager;

    (void) ac;

    nts::Parser parser(factory, manager, args[1]);
    parser.run();

    nts::ConsoleAnalyser console(manager, (size_t) ac, args);
    console.parse_options();
    return (0);
}
