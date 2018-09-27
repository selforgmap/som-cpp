//
// Created by Sumedhe Dissanayake on 10/3/18.
//

#ifndef SOM_RECTANGULAR_H
#define SOM_RECTANGULAR_H

#include "../struct/position.h"

class Rectangular {
public:
    int height;
    int width;
    int no_of_neurones;

    /**
     * Constructor of rectangular
     * @param width Width of the lattice
     * @param height Height of the lattice
     */
    Rectangular(int width,
                int height);

    /**
     * Get the (x,y) coordinates of a neurone
     * @param neurone_index Index of the neurone
     * @param rect Rectangular instance
     * @return Position of the neurone
     */
    static Position GetPosition(
            int neurone_index,
            Rectangular rectangular);

    /**
     * Get distance between two neurones
     * @param neurone1 Index of the neurone 1
     * @param neurone2 Index of the neurone 2
     * @param rect Rectangular instance
     * @return Distance between two neurones
     */
    static double GetDistance(
            int neurone_index_a,
            int neurone_index_b,
            Rectangular rectangular);
};


#endif //SOM_RECTANGULAR_H
