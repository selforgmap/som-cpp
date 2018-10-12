//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include "Trainer.h"

Trainer::Trainer(Grid* grid, vector<vector<float>> input_space, int iterations, float learning_rate, int initial_radius){
    this->grid           = grid;
    this->input_space    = input_space;
    this->iterations     = iterations;
    this->learning_rate  = learning_rate;
    this->initial_radius = initial_radius;
}
