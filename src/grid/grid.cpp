//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#include "grid.h"

#include <limits>

#include "../utils/math_helper.h"
#include "../utils/trainer_helper.h"

float Grid::CalculateDistance(Position pos1, Position pos2) {
    return euclidean_distance(pos1, pos2);
}

int Grid::FindBMU(vector<float> input_vector) {
    float min_dist = std::numeric_limits<float>::max();
    int bmu = -1;
    for (int i = 0; i < this->neurones.size(); ++i) {
        float dist = squared_euclidean_distance(input_vector, neurones[i]);
        if (dist < min_dist){
            min_dist = dist;
            bmu = i;
        }
    }
    return bmu;
}