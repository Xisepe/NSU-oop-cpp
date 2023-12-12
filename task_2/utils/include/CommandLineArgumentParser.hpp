//
// Created by maxim on 22.10.2022.
//

#ifndef TASK_2_COMMANDLINEARGUMENTPARSER_HPP
#define TASK_2_COMMANDLINEARGUMENTPARSER_HPP

#include "Parser.hpp"
#include "CommandLineArguments.hpp"


class CommandLineArgumentParser : Parser<CommandLineArguments> {
private:
    int _argc;
    char **_argv;
public:
    CommandLineArgumentParser(int argc, char **argv);

    CommandLineArguments parse() const override;
};


#endif //TASK_2_COMMANDLINEARGUMENTPARSER_HPP
