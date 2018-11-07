//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#include "trainer_helper.h"

#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <random>
#include <random>

#include <iostream>

void initialize_random_weights(Grid* grid, int min, int max){
    srand((uint)time(0));

    for (int i = 0; i < grid->Size(); ++i){
        std::vector<double> neu = vector<double>((u_long)grid->dimention);
        for (int j = 0; j < grid->dimention; ++j){
            neu[j] = (rand() % ((max - min) + 1) + min);
        }
        grid->nodes[i].features = neu;
    }

}

float squared_euclidean_distance(vector<double> input_features, vector<double> node_features){
    float dist = 0;
    for (int i = 0; i < node_features.size(); ++i) {
        dist += pow((input_features[i] - node_features[i]), 2);
    }
    return dist;
}

float euclidean_distance(float x1, float y1, float x2, float y2) {
    return (float)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

