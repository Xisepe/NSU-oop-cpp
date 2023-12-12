//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_GAMEVIEW_HPP
#define TASK_2_GAMEVIEW_HPP

#include "CellField.h"
#include "GameSettings.hpp"
#include <string>
#include <utility>
#include <fstream>

class GameView {
protected:
    std::string _aliveCellFill;
    std::string _deadCellFill;
    inline static const std::string _FOLDER = "ASSETS/";

    GameView(const GameView&);

    GameView(std::string aliveCellFill,
             std::string deadCellFill) :
            _aliveCellFill(std::move(aliveCellFill)),
            _deadCellFill(std::move(deadCellFill)) {}



    void printInStream(
            std::ostream &out,
            const CellField &cellField,
            const GameSettings &settings) const;

public:
    void save(const std::string& filename,
              const CellField &cellField,
              const GameSettings &settings) const;

public:
    virtual ~GameView(){};
    virtual void display(const CellField &cellField, const GameSettings &settings) const = 0;
};


#endif //TASK_2_GAMEVIEW_HPP
