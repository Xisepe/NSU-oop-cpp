//
// Created by maxim on 15.10.2022.
//
#include "Cell.hpp"
#include <utility>

const bool &Cell::isAlive() const {
    return this->_alive;
}

void Cell::setAlive(bool isAlive) {
    this->_alive = isAlive;
}

Cell::Cell(bool alive) : _alive(alive) {}

Cell::Cell(const Cell &cell) : _alive(cell.isAlive()) {}

Cell &Cell::operator=(const Cell &cell) {
    if (this != &cell) {
        _alive = cell.isAlive();
    }
    return *this;
}
