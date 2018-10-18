//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include "trainer.h"

#include <iostream>

#include "../helpers/neighbourhood_function.h"
#include "../helpers/learning_rate.h"

Trainer::Trainer(Grid* grid, vector<vector<float>> &input_space, int iteration_limit, float starting_learning_rate){
    this->grid                   = grid;
    this->input_space            = input_space;
    this->iteration_limit        = iteration_limit;
    this->starting_learning_rate = starting_learning_rate;

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

void Trainer::Train(){
    // For each iteration
    for (int i = 1; i <= this->iteration_limit; ++i){

        // Get next input vector
        vector<float> input_vector = this->GetNextInputVector();

        // Find the best matching unit
        int bmu_index = this->grid->FindBMU(input_vector);
        Node bmu = this->grid->nodes[bmu_index];


        cout << "iv:" << input_vector[0] << " " << input_vector[1] << " " << input_vector[2] << endl;
        cout << "bmu:" << bmu_index << endl;
        vector<float> wv = this->grid->nodes[bmu_index].weight_vector;
        std::cout << wv[0] << " " << wv[1] << " " << wv[2] << endl;

        // Calculate learning rate
        float learning_rate = constant_learning_rate(this->starting_learning_rate);

        // For each node
        for (int n = 0; n < this->grid->nodes.size(); ++n) {
            Node &node = this->grid->nodes[n];

            // Calculate neighbourhood value
            float neighbourhood_value = bubble_neighbourhood(bmu, n, i);

            // Adapt the neurone
            for (int d = 0; d < this->grid->dimention; ++d) {
                node.weight_vector[d] +=
                        learning_rate * neighbourhood_value * (input_vector[d] - node.weight_vector[d]);
            }

        }


    }
}