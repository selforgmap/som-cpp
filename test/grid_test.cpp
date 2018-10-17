//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#include "gtest/gtest.h"
#include "core/grid.h"
#include "grids/rectangular.h"
#include "core/trainer.h"
#include "struct/node.h"


/**
 * Test Get Position of Rectangular Grid
 */
TEST(RectangularGrid, GetPosition){
    Grid* grid = new Rectangular(10, 10, 3);
    grid->InitializeNodes();

    Node node = grid->nodes[25];
    ASSERT_EQ(node.x_pos, 5);
    ASSERT_EQ(node.y_pos, 2);
}

/**
 * Test Find BMU
 */
TEST(FindBMU, Manual){
    Grid* grid = new Rectangular(2, 2, 3, false);
    grid->InitializeNodes();

    grid->nodes[0].weight_vector = vector<float>{10, 20, 30};
    grid->nodes[1].weight_vector = vector<float>{-10, 2, 7};
    grid->nodes[2].weight_vector = vector<float>{1, 2, 5};
    grid->nodes[3].weight_vector = vector<float>{-5, -4, -3};

    vector<float>vec = {3, 4, 5};
    int bmu = grid->FindBMU(vec);

    ASSERT_EQ(bmu, 2);
}

/**
 * Test Calculate Distance
 */
TEST(CalculateDistance, TwoPointers){
    Node n1;
    Node n2;
    n1.x_pos = 6;
    n1.y_pos = 11;
    n2.x_pos = 3;
    n2.y_pos = 7;

    Rectangular grid = Rectangular(10, 10, 3);
    float dist = grid.CalculateDistance(n1, n2);
    ASSERT_NEAR(dist, 5.0, 1.0e-5);
}