//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#include "neighbourhood_function.h"

#include <iostream>

float bubble_neighbourhood(Node bmu, int node_index, int iteration){
    // TODO
    if (bmu.distance_to[node_index] > 1){
        return 0;
    } else {
        return 1;
    }
}

