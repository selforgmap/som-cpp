//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include <vector>
#include <iostream>

#include "grid.h"
#include "../helpers/learning_rate.h"
#include "../helpers/neighborhood.h"
#include "../struct/dataitem.h"

#ifndef SOM_TRAINER_H
#define SOM_TRAINER_H

using namespace std;

/**
 * SOM class
 */
class SOM {
public:
    int x_dim;
    int y_dim;
    int dimension;
    string grid_type;
    int iteration_limit;
    float starting_learning_rate;
    string node_initialization_method;
    LearningRate::type learning_rate_type;
    Neighborhood::type neighborhood_type;
    double min_node_weight;
    double max_node_weight;

    Grid* grid;
    vector<DataItem> dataset;
    int current_iteration;
    int selected_dataitem_index;

    /**
     * Consturctor
     * @param config Configurations
     */
    SOM();

    /**
     * Initialize nodes
     */
    void Initialize();

    /**
     * Get the next input vector
     * @param is_random Random selection of the next input vector
     * @return The next data item
     */
    DataItem GetNextDataItem(bool is_random = false);

    /**
     * Start training
     * @param dataset Input dataset for the train
     */
    void Train(vector<DataItem> &dataset);

};

#endif //SOM_TRAINER_H
