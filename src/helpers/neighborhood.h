//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#ifndef SOM_NEIGHBORHOOD_FUNCTION_H
#define SOM_NEIGHBORHOOD_FUNCTION_H

#include <map>

#include "../struct/node.h"

class Neighborhood {
public:
    enum type {
        NF_BUBBLE,
        NF_GAUSSIAN
    };

    // To convert string to learning rate type
    static std::map<std::string, Neighborhood::type> type_map;

    /**
     * Calculate Neighborhood
     * @param type neighborhood function
     * @return Neighborhood function
     */
    static float Calculate(Neighborhood::type type, Node bmu, int node_index, int iteration);

private:
    /**
     * Returns the bubble neighborhood value
     * @param Node The best matching unit
     * @param node_index Index of the selected node
     * @param iteration Current iteration
     * @return Neighborhood value
     */
    static float BubbleNeighborhood(Node bmu, int node_index, int iteration);

    /**
     * Returns the gaussian neighborhood value
     * @param bmu The best matching unit
     * @param node_index Index of the selected node
     * @param iteration Current iteration
     * @return Neighborhood value
     */
    static float GaussianNeighborhood(Node bmu, int node_index, int iteration);
};




#endif //SOM_NEIGHBORHOOD_FUNCTION_H
