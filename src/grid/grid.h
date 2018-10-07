//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#ifndef SOM_GRID_H
#define SOM_GRID_H

#include <vector>

#include "../struct/position.h"
#include "../utils/math_helper.h"

using namespace std;

class Grid {
public:
    int width;
    int height;
    int dimention;
    int no_of_neurones;
    vector<vector<float>> neurones;

    /**
     * Constructor
     * @param width Width of the grid
     * @param height Height of the grid
     * @param dimention Dimention of dataset
     * @param random_initialization Random Initialization of data
     */
    Grid(int width, int height, int dimention, bool random_initialization = true){
        this->width = width;
        this->height = height;
        this->dimention = dimention;
        this->no_of_neurones = width * height;

        if (random_initialization){
            // GENERATE RANDOM VALUES
        }

    }

    /**
     * Get the (x,y) coordinates of a neurone
     * @param neurone_index Index of the neurone
     * @return Position of the neurone
     */
    virtual Position GetPosition(int neurone_index) = 0;

    /**
     * Find the Best Matching Unit (BMU) for a given vector
     * @param input_vector Input vector to find BMU
     * @return Index of the neurone
     */
    int FindBMU(vector<float> input_vector);


    /**
     * Get distance between two neurones
     * @param neurone1 Index of the neurone 1
     * @param neurone2 Index of the neurone 2
     * @return Distance between two neurones
     */
     static float CalculateDistance(Position pos1, Position pos2);


};


#endif //SOM_GRID_H
