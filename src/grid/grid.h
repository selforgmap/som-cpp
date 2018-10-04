//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#ifndef SOM_GRID_H
#define SOM_GRID_H

#include "../struct/position.h"
#include "../utils/math_helper.h"

class Grid {
public:
    int width;
    int height;
    int no_of_neurones;

    /**
     * Get the (x,y) coordinates of a neurone
     * @param neurone_index Index of the neurone
     * @return Position of the neurone
     */
    virtual Position GetPosition(int neurone_index) = 0;

    /**
     * Get distance between two neurones
     * @param neurone1 Index of the neurone 1
     * @param neurone2 Index of the neurone 2
     * @return Distance between two neurones
     */
     static double CalculateDistance(Position pos1, Position pos2);
};


#endif //SOM_GRID_H
