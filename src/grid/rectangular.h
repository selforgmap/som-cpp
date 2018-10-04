//
// Created by Sumedhe Dissanayake on 10/3/18.
//

#ifndef SOM_RECTANGULAR_H
#define SOM_RECTANGULAR_H

#include "../struct/position.h"
#include "grid.h"

class Rectangular : public Grid {
public:
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
     * @return Position of the neurone
     */
    Position GetPosition(int neurone_index);

};


#endif //SOM_RECTANGULAR_H
