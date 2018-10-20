//
// Created by Sumedhe Dissanayake on 10/20/18.
//

#ifndef SOM_CONFIG_H
#define SOM_CONFIG_H

#endif //SOM_CONFIG_H

#include <string>

using namespace std;

struct Config {
    int x_dim;
    int y_dim;
    int dimention;
    string grid_type;
    int iteration_limit;
    float starting_learning_rate;
    string node_initialization_method;
    string learning_rate_function;
    string neighbourhood_function;
    int min_node_weight;
    int max_node_weight;
};