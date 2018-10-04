//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#include "grid.h"
#include "../utils/math_helper.h"

double Grid::CalculateDistance(Position pos1, Position pos2) {
    return utils::euclidean_distance(pos1, pos2);
}

int foo(){
    return 10;
}