#include "main.h"

#include <iostream>
#include <vector>

#include "config.h"
#include "utils/csv_loader.h"
#include "core/trainer.h"
#include "grids/rectangular.h"

#include "helpers/trainer_helper.h"
#include "struct/node.h"

using namespace std;

int main() {

    // Configurations
    Config config;
    config.x_dim                      = 10;
    config.y_dim                      = 10;
    config.dimention                  = 3;
    config.grid_type                  = "RECTANGULAR";
    config.iteration_limit            = 100;
    config.starting_learning_rate     = 0.5;
    config.node_initialization_method = "RANDOM";
    config.learning_rate_function     = "CONSTANT_LEARNING_RATE";
    config.neighbourhood_function     = "BUBBLE_NEIGHBOURHOOD";
    config.min_node_weight            = DEFAULT_MIN_WEIGHT;
    config.max_node_weight            = DEFAULT_MAX_WEIGHT;


    // Create trainer
    Trainer trainer(config);
    cout << trainer.grid->ToString() << endl;

    // Load dataset from file
    vector<vector<float>> input_space = load_csv(INPUT_PATH);

    // Train
    trainer.Train(input_space);
    cout << trainer.grid->ToString();


    std::cout << "Program is running..." << std::endl;
    return 0;
}
