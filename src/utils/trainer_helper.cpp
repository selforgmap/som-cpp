//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#include "trainer_helper.h"

#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>

#include <iostream>

void initialize_random_weights(Grid* grid, int min, int max){
    srand(time(0));

    for (int i = 0; i < grid->no_of_neurones; ++i){
        std::vector<float> neu;
        for (int j = 0; j < grid->dimention; ++j){
            neu.push_back(rand() % ((max - min) + 1) + min);
        }
        grid->neurones.push_back(neu);
    }

}

float squared_euclidean_distance(vector<float> input_vector, vector<float> weight_vector){
    float dist = 0;
    for (int i = 0; i < weight_vector.size(); ++i) {
        dist += pow((input_vector[i] - weight_vector[i]), 2);
    }
    return dist;
}
