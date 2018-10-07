//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#include "trainer_helper.h"

#include <ctime>
#include <cstdlib>
#include <vector>

#include <iostream>

void initialize_random_weights(Grid* grid, int min, int max){
    srand(time(0));

    for (int i = 0; i < grid->no_of_neurones; ++i){
        std::vector<int> neu;
        for (int j = 0; j < grid->dimention; ++j){
            neu.push_back(rand() % ((max - min) + 1) + min);
        }
        grid->neurones.push_back(neu);
    }

}
