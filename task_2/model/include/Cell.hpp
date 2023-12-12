//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_CELL_H
#define TASK_2_CELL_H
class Cell {
private:
    bool _alive;
public:
    Cell(): _alive(false){};
    Cell(bool alive);
    Cell(const Cell&);
    const bool& isAlive() const;
    void setAlive(bool isAlive);
    Cell& operator =(const Cell&);
};
#endif //TASK_2_CELL_H
