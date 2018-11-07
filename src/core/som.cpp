//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include "som.h"

#include <iostream>
#include <stdlib.h>
#include <zconf.h>

#include "../init.h"
#include "../helpers/neighborhood.h"
#include "../helpers/learning_rate.h"
#include "../grids/rectangular.h"
#include "../helpers/trainer_helper.h"


SOM::SOM(){
    this->x_dim                      = DEFAULT_X_DIM;
    this->y_dim                      = DEFAULT_Y_DIM;
    this->dimension                  = DEFUALT_DIMENSION;
    this->grid_type                  = DEFAULT_GRID_TYPE;
    this->iteration_limit            = DEFAULT_ITERATION_LIMIT;
    this->starting_learning_rate     = DEFAULT_STARTING_LEARNING_RATE;
    this->node_initialization_method = DEFAULT_NODE_INITIALIZATION_METHOD;
    this->learning_rate_type         = DEFAULT_LEARNING_RATE_TYPE;
    this->neighborhood_type          = DEFAULT_NEIGHBORHOOD_TYPE;
    this->min_node_weight            = DEFAULT_MIN_NODE_WEIGHT;
    this->max_node_weight            = DEFAULT_MAX_NODE_WEIGHT;
}


void SOM::Initialize() {

    // Greate grid
    if (this->grid_type == "RECTANGULAR"){
        this->grid = new Rectangular(this->x_dim, this->y_dim, this->dimension);
    }
    this->grid->InitializeNodes(); // TODO: Initialization method
    initialize_random_weights(this->grid, this->min_node_weight, this->max_node_weight);

    // Reset values
    this->current_iteration = 0;
    this->selected_dataitem_index = -1;
}


DataItem SOM::GetNextDataItem(bool is_random) {
    // Select next input vector index
    if (is_random){
        this->selected_dataitem_index = (int)(rand() % this->dataset.size());
    } else {
        this->selected_dataitem_index = (int)((this->selected_dataitem_index + 1) % this->dataset.size());
    }

    return this->dataset[this->selected_dataitem_index];
}


void SOM::Train(vector<DataItem> &dataset){
    // Set input dataset
    this->dataset = dataset;

    // For each iteration
    for (int i = 1; i <= this->iteration_limit; ++i){

        // Get next input vector
        DataItem dataitem = this->GetNextDataItem();

        // Find the best matching unit
        int bmu_index = this->grid->FindBMU(dataitem.features);
        Node bmu = this->grid->nodes[bmu_index];

        // Calculate learning rate
        float learning_rate = LearningRate::Calculate(
                this->learning_rate_type,
                this->starting_learning_rate,
                this->current_iteration,
                this->iteration_limit);

        // For each node
        for (int n = 0; n < this->grid->nodes.size(); ++n) {
            Node &node = this->grid->nodes[n];

            // Calculate neighborhood value
            float neighborhood_value = Neighborhood::Calculate(this->neighborhood_type, bmu, n, i);

            // Adapt the neurone
            for (int d = 0; d < this->grid->dimention; ++d) {
                node.features[d] +=
                        learning_rate * neighborhood_value * (dataitem.features[d] - node.features[d]);
            }

        }

    }
}