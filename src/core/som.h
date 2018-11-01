//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include <vector>

#include "grid.h"
#include "../struct/config.h"

#ifndef SOM_TRAINER_H
#define SOM_TRAINER_H

using namespace std;

/**
 * SOM class
 */
class SOM {
public:
    vector<vector<float> > input_space;
    Grid* grid;
    int current_iteration;
    int selected_input_vector_index;
    Config config;

    SOM();

    /**
     * Consturctor
     * @param config Configurations
     */
    SOM(Config config);

    /**
     * Get the next input vector
     * @param is_random Random selection of the next input vector
     * @return The next input vector
     */
    vector<float> GetNextInputVector(bool is_random = false);

    /**
     * Start training
     * @param input_space Input space for the train
     */
    void Train(vector<vector<float> > &input_space);
};

#endif //SOM_TRAINER_H
