//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#include "neighborhood.h"

#include <iostream>

std::map<std::string, Neighborhood::type> Neighborhood::type_map = {
        { "BUBBLE", NF_BUBBLE }
};

float Neighborhood::Calculate(Neighborhood::type type, Node bmu, int node_index, int iteration) {
    switch (type){
        case NF_BUBBLE:
            return Neighborhood::BubbleNeighborhood(bmu, node_index, iteration);
        case NF_GAUSSIAN:
            return Neighborhood::GaussianNeighborhood(bmu, node_index, iteration);
    }
}

float Neighborhood::BubbleNeighborhood(Node bmu, int node_index, int iteration){
    // TODO:
    if (bmu.distance_to[node_index] > 2){
        return 0;
    } else {
        return 1;
    }
}

float Neighborhood::GaussianNeighborhood(Node bmu, int node_index, int iteration) {
    // TODO:
    return 1;
}
