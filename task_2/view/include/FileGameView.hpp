//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_FILEGAMEVIEW_HPP
#define TASK_2_FILEGAMEVIEW_HPP

#include "GameView.hpp"

class FileGameView : public GameView {
private:
    std::string _filepath;
public:
    FileGameView(std::string aliveCellFill, std::string deadCellFill, std::string filepath);
    void display(const CellField &cellField, const GameSettings &settings) const override;
};


#endif //TASK_2_FILEGAMEVIEW_HPP
