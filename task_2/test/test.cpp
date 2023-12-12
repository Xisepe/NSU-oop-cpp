//
// Created by Maxim on 07.11.2022.
//
#include <gtest/gtest.h>
#include "CellField.h"
#include "GameSettings.hpp"
#include "LogicController.hpp"

TEST(LogicTest, LogicController) {
  LogicController controller({3},{2,3});
  CellField field = CellField::Builder().withStartCells({{1,1},{1,2},{1,3}}).build();
  EXPECT_FALSE(controller.calculateNewCellState(1, true));
  EXPECT_EQ(controller.countAliveNeighbors(field,1,2),2);

}