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

    Rectangular(int width, int height);

    static Position GetPosition(int neurone_index, Rectangular rectangular);

    static double GetDistance(int neurone_index_a, int neurone_index_b, Rectangular rectangular);
};


#endif //SOM_RECTANGULAR_H
