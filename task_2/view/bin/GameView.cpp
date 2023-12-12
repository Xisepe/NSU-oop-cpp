//
// Created by maxim on 23.10.2022.
//

#include <GameView.hpp>

void GameView::printInStream(
        std::ostream &out,
        const CellField &cellField,
        const GameSettings &settings) const {
    out << settings;
    size_t rows = cellField.rows();
    size_t columns = cellField.columns();

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            std::string fill;
            if (cellField.getCellAtPosition(j, i).isAlive()) {
                fill = _aliveCellFill;
            } else {
                fill = _deadCellFill;
            }
            out << fill;
        }
        out << std::endl;
    }

}

void GameView::save(const std::string& filename, const CellField &cellField, const GameSettings &settings) const {
    std::ofstream fout(_FOLDER + filename);
    printInStream(fout, cellField, settings);
    fout.close();
}

GameView::GameView(const GameView &view) :_aliveCellFill(view._aliveCellFill),_deadCellFill(view._deadCellFill){}
