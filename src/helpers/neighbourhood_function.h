//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#ifndef SOM_NEIGHBOURHOOD_FUNCTION_H
#define SOM_NEIGHBOURHOOD_FUNCTION_H

#include "../struct/node.h"

/**
 * Returns the bubble neighbourhood value
 * @param Node The best matching unit
 * @param node_index Index of the selected node
 * @param iteration Current iteration
 * @return Neighbourhood value
 */
float bubble_neighbourhood(Node bmu, int node_index, int iteration);

#endif //SOM_NEIGHBOURHOOD_FUNCTION_H
