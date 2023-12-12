//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_CONSOLEGAMEVIEW_HPP
#define TASK_2_CONSOLEGAMEVIEW_HPP

#include <CellField.h>

#include <utility>
#include "GameView.hpp"

class ConsoleGameView : public GameView {
public:
    ConsoleGameView(std::string aliveFill, std::string deadFill);
    void display(const CellField &cellField, const GameSettings &settings) const override;
    ~ConsoleGameView(){};
};


#endif //TASK_2_CONSOLEGAMEVIEW_HPP
