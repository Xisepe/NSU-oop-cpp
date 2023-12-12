//
// Created by maxim on 15.10.2022.
//

#include "FileGameView.hpp"
#include <fstream>
#include <iostream>


FileGameView::FileGameView(std::string aliveCellFill, std::string deadCellFill, std::string filepath) :
        GameView(
                std::move(aliveCellFill),
                std::move(deadCellFill)
        ),
        _filepath(std::move(filepath)) {}

void FileGameView::display(const CellField &cellField, const GameSettings &settings) const {
    save(_filepath,cellField,settings);
}
