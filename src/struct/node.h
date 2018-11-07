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
    vector<double> features;
    float x_pos;
    float y_pos;
    vector<float> distance_to;
};

#endif //SOM_NODE_H
