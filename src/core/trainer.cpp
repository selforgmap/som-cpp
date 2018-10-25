//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include "trainer.h"

#include <iostream>
#include <stdlib.h>
#include <zconf.h>

#include "../helpers/neighbourhood_function.h"
#include "../helpers/learning_rate.h"
#include "../grids/rectangular.h"
#include "../helpers/trainer_helper.h"


Trainer::Trainer(Config config){
    this->config = config;

    // Greate grid
    if (config.grid_type == "RECTANGULAR"){
        this->grid = new Rectangular(config.x_dim, config.y_dim, config.dimension);
    }
    this->grid->InitializeNodes(); // TODO: Initialization method
    initialize_random_weights(this->grid, config.min_node_weight, config.max_node_weight);

    // Reset values
    this->current_iteration = 0;
    this->selected_input_vector_index = -1;
}


vector<float> Trainer::GetNextInputVector(bool is_random) {
    // Select next input vector index
    if (is_random){
        this->selected_input_vector_index = (int)(rand() % this->input_space.size());
    } else {
        this->selected_input_vector_index = (int)((this->selected_input_vector_index + 1) % this->input_space.size());
    }

    return this->input_space[this->selected_input_vector_index];
}


void Trainer::Train(vector<vector<float>> &input_space){
    this->input_space = input_space;

    // For each iteration
    for (int i = 1; i <= this->config.iteration_limit; ++i){

        // Get next input vector
        vector<float> input_vector = this->GetNextInputVector();

        // Find the best matching unit
        int bmu_index = this->grid->FindBMU(input_vector);
        Node bmu = this->grid->nodes[bmu_index];

        // Calculate learning rate
        float learning_rate = LearningRate::Calculate(
                this->config.learning_rate_type,
                this->config.starting_learning_rate,
                this->current_iteration,
                this->config.iteration_limit);

        // For each node
        for (int n = 0; n < this->grid->nodes.size(); ++n) {
            Node &node = this->grid->nodes[n];

            // Calculate neighbourhood value
            float neighbourhood_value;
            if (this->config.neighbourhood_function == "BUBBLE_NEIGHBOURHOOD"){
                neighbourhood_value = bubble_neighbourhood(bmu, n, i);
            }

            // Adapt the neurone
            for (int d = 0; d < this->grid->dimention; ++d) {
                node.weight_vector[d] +=
                        learning_rate * neighbourhood_value * (input_vector[d] - node.weight_vector[d]);
            }

        }

    }
}