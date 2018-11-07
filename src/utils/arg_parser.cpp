//
// Created by Sumedhe Dissanayake on 10/28/18.
//

#include "arg_parser.h"

#include <iostream>
#include <string>
#include <stdlib.h>

#include "../helpers/learning_rate.h"
#include "../helpers/neighborhood.h"
#include "../core/som.h"

using namespace std;

void parse_config_from_args(SOM som, int argc, char** argv){
    try{
        // For each argument
        for (int i = 1; i < argc; ++i){
            string opt = argv[i];

            if (opt == "-x" || opt == "-xdim") {
                // X dimension size
                som.x_dim = atoi(argv[++i]);
            } else if (opt == "-y" || opt == "-ydim") {
                // Y dimension size
                som.y_dim = atoi(argv[++i]);
            } else if (opt == "-d" || opt == "-dimension") {
                // Dimension
                som.dimension = atoi(argv[++i]);
            } else if (opt == "-g" || opt == "-grid-type") {
                // Grid Type
                som.grid_type = argv[++i];
            } else if (opt == "-t" || opt == "-iteration-limit"){
                // Iteration limit
                som.iteration_limit = atoi(argv[++i]);
            } else if (opt == "-lr" || opt == "-starting-learning-rate"){
                // Starting learning rate
                som.starting_learning_rate = (float)atof(argv[++i]);
            } else if (opt == "-m" || opt == "-node-init-method"){
                // Node initialization method
                som.node_initialization_method = argv[++i];
            } else if (opt == "-lf" || opt == "-learning-rate-type"){
                // Learning rate type
                som.learning_rate_type = (LearningRate::type_map[argv[++i]]);
            } else if (opt == "-nf" || opt == "-neighborhood-type"){
                // Neighborhood function
                som.neighborhood_type = Neighborhood::type_map[argv[++i]];
            } else if (opt == "-min" || opt == "-min-node-weight"){
                // Minimum node weight (For random initialization)
                som.min_node_weight = (float)atof(argv[++i]);
            } else if (opt == "-max" || opt == "-max-node-weight"){
                // Maximum node weight (For random initialization)
                som.max_node_weight = (float)atof(argv[++i]);
            }

        }
    } catch (int e){
        cout << "Error in parsing args!" << endl;
    }

}
