//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#ifndef SOM_GRID_H
#define SOM_GRID_H

#include <vector>

#include "../utils/math_helper.h"
#include "../struct/node.h"

using namespace std;

class Grid {
public:
    int x_dim;
    int y_dim;
    int dimention;
    vector<Node> nodes;

    /**
     * Constructor
     * @param x_dim X Dimention of the grid
     * @param y_dim Y Dimention of the grid
     * @param dimention Dimention of dataset
     * @param random_initialization Random Initialization of data
     */
    Grid(int x_dim, int y_dim, int dimention, bool random_initialization = true);

    /**
     * Initialize Nodes
     * Set (x,y) coordinates in each node
     * Calculate distances between each pair of nodes
     */
    void InitializeNodes();

    /**
     * Find the Best Matching Unit (BMU) for a given vector
     * @param input_vector Input vector to find BMU
     * @return Index of the neurone
     */
    int FindBMU(vector<float> input_vector);

    /**
     * Calculate the distance between two nodes
     * @param node1 Node 1
     * @param node2 Node 2
     * @return The distance
     */
    float CalculateDistance(Node node1, Node node2);

    /**
     * Get the size of the weight matrix / nodes vector
     * @return Size
     */
    int Size();

    /**
     * Return grid information
     */
    string ToString();


    /**
     * Calculate the (x,y) coordinates of the location of a node
     * @param node_index Index of the node
     * @return Pair of x,y coordinates
     */
    virtual pair<float, float> CalculateLocation(int node_index) = 0;


};


#endif //SOM_GRID_H
