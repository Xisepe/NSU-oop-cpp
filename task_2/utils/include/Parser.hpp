//
// Created by maxim on 22.10.2022.
//

#ifndef TASK_2_PARSER_HPP
#define TASK_2_PARSER_HPP

#include <iostream>
#include <fstream>

template <class T>
class Parser {
public:
    virtual T parse() const = 0;
};

#endif //TASK_2_PARSER_HPP
