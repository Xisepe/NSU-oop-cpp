//
// Created by maxim on 15.10.2022.
//

#include <iostream>
#include <string>
#include "ConsoleGameView.hpp"

void ConsoleGameView::display(const CellField &cellField, const GameSettings &settings) const {
    GameView::printInStream(std::cout, cellField, settings);
}

ConsoleGameView::ConsoleGameView(std::string aliveFill, std::string deadFill) :
        GameView(
                std::move(aliveFill),
                std::move(deadFill)
        ) {}
