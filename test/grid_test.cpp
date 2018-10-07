//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#include "gtest/gtest.h"
#include "struct/position.h"
#include "grid/grid.h"
#include "grid/rectangular.h"
#include "utils/math_helper.h"
#include "core/trainer.h"

/**
 * Test Calculate Distance
 */
TEST(CalculateDistance, TwoPointers){
    Position p1 = {6, 11};
    Position p2 = {3, 7};
    double dist = Grid::CalculateDistance(p1, p2);
    ASSERT_NEAR(dist, 5.0, 1.0e-5);
}

/**
 * Test Get Position of Rectangular Grid
 */
TEST(RectangularGrid, GetPosition){
    Grid* grid = new Rectangular(10, 10, 3);
    Position pos = grid->GetPosition(25);
    ASSERT_EQ(pos.x, 5);
    ASSERT_EQ(pos.y, 2);
}

/**
 * Test Find BMU
 */
TEST(FindBMU, Manual){
    Grid* grid = new Rectangular(2, 2, 3, false);

    grid->neurones.push_back(vector<float>{10, 20, 30});
    grid->neurones.push_back(vector<float>{-10, 2, 7});
    grid->neurones.push_back(vector<float>{1, 2, 5});
    grid->neurones.push_back(vector<float>{-5, -4, -3});

    vector<float>vec = {3,4,5};
    int bmu = grid->FindBMU(vec);

    ASSERT_EQ(bmu, 2);
}