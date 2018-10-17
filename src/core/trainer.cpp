//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include "Trainer.h"

#include <iostream>

Trainer::Trainer(Grid* grid, vector<vector<float>> &input_space, int iteration_limit, float learning_rate){
    this->grid              = grid;
    this->input_space       = input_space;
    this->iteration_limit   = iteration_limit;
    this->learning_rate     = learning_rate;

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
    // Iteration
    for (int i = 0; i < this->iteration_limit; ++i){
        // Get next input vector
        vector<float> input_vector = this->GetNextInputVector();

        // Find the best matching unit
        int bmu_index = this->grid->FindBMU(input_vector);



    }
}