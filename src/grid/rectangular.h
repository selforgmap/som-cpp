//
// Created by Sumedhe Dissanayake on 10/3/18.
//

#ifndef SOM_RECTANGULAR_H
#define SOM_RECTANGULAR_H

#include "grid.h"

class Rectangular : public Grid {
public:
     /**
      * Constructor of rectangular
      * @param x_dim X Dimention of the lattice
      * @param y_dim Y Dimention of the lattice
      * @param dimention Dimention of the dataset
      * @param random_initialization Random Initialization of data
      */
    Rectangular(int x_dim,
                int y_dim,
                int dimention,
                bool random_initialization = true);


    /**
     * Calculate the (x,y) coordinates of the location of a node
     * @param node_index Index of the node
     * @return Pair of x,y coordinates
     */
    pair<float, float> CalculateLocation(int node_index);



};


#endif //SOM_RECTANGULAR_H
