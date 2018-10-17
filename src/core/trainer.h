//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include <vector>

#include "grid.h"

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
    int iteration_limit;
    float learning_rate;

    int current_iteration;
    int selected_input_vector_index;

    /**
     * Constructor
     * @param input_space Input space
     * @param grid Grid
     * @param iterations No of iterations
     * @param learning_rate Learning rate (alpha)
     * @param initial_radius Initial radius
     */
    Trainer(Grid* grid,
            vector<vector<float>> &input_space,
            int iteration_limit,
            float learning_rate);


    /**
     * Get the next input vector
     * @param is_random Random selection of the next input vector
     * @return The next input vector
     */
    vector<float> GetNextInputVector(bool is_random = false);

    /**
     * Start training
     */
    void Train();
};

#endif //SOM_TRAINER_H
