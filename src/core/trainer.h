//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include <vector>

#include "../grid/grid.h"

#ifndef SOM_TRAINER_H
#define SOM_TRAINER_H

using namespace std;

/**
 * Trainer class
 */
class Trainer {
public:
    vector<vector<float>> input_space;
    Grid* grid;
    int iterations;
    float learning_rate;
    int initial_radius;

    /**
     * Constructor
     * @param input_space Input space
     * @param grid Grid
     * @param iterations No of iterations
     * @param learning_rate Learning rate (alpha)
     * @param initial_radius Initial radius
     */
    Trainer(Grid* grid,
            vector<vector<float>> input_space,
            int iterations,
            float learning_rate,
            int initial_radius);
};

#endif //SOM_TRAINER_H
