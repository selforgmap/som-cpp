//
// Created by Sumedhe Dissanayake on 10/28/18.
//

#include "arg_parser.h"

#include <iostream>
#include <string>
#include <stdlib.h>

#include "../helpers/learning_rate.h"

using namespace std;

Config argsToConfig(int argc, char** argv){
    Config config;

    try{
        // For each argument
        for (int i = 1; i < argc; ++i){
            string opt = argv[i];

            if (opt == "-x" || opt == "-xdim") {
                // X dimension size
                config.x_dim = atoi(argv[++i]);
            } else if (opt == "-y" || opt == "-ydim") {
                // Y dimension size
                config.y_dim = atoi(argv[++i]);
            } else if (opt == "-d" || opt == "-dimension") {
                // Dimension
                config.dimension = atoi(argv[++i]);
            } else if (opt == "-g" || opt == "-grid-type") {
                // Grid Type
                config.grid_type = argv[++i];
            } else if (opt == "-t" || opt == "-iteration-limit"){
                // Iteration limit
                config.iteration_limit = atoi(argv[++i]);
            } else if (opt == "-lr" || opt == "-starting-learning-rate"){
                // Starting learning rate
                config.starting_learning_rate = (float)atof(argv[++i]);
            } else if (opt == "-m" || opt == "-node-init-method"){
                // Node initialization method
                config.node_initialization_method = argv[++i];
            } else if (opt == "-lf" || opt == "-learning-rate-type"){
                // Learning rate type
                config.learning_rate_type = (LearningRate::type_map[argv[++i]]);
            } else if (opt == "-nf" || opt == "-neighbourhood-function"){
                // Neighbourhood function
                config.neighbourhood_function = argv[++i];
            } else if (opt == "-min" || opt == "-min-node-weight"){
                // Minimum node weight (For random initialization)
                config.min_node_weight = (float)atof(argv[++i]);
            } else if (opt == "-max" || opt == "-max-node-weight"){
                // Maximum node weight (For random initialization)
                config.max_node_weight = (float)atof(argv[++i]);
            } else if (opt == "-i" || opt == "-input"){
                // Input file path (.csv file)
                config.input_file_path = argv[++i];
            }

        }
    } catch (int e){
        cout << "Error in parsing args!" << endl;
    }

    return config;
}
