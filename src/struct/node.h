//
// Created by Sumedhe Dissanayake on 10/8/18.
//

#ifndef SOM_NODE_H
#define SOM_NODE_H

#include <vector>

using namespace std;

/**
 * Node structure
 */
struct Node {
    vector<float> weight_vector;
    int x_pos;
    int y_pos;
    vector<float> distance_to;
};

#endif //SOM_NODE_H
