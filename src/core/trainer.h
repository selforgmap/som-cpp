//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include <vector>

#include "../grid/grid.h"

#ifndef SOM_TRAINER_H
#define SOM_TRAINER_H

class trainer {
public:
    std::vector<std::vector<int>> dataset;
    Grid* grid;
};

#endif //SOM_TRAINER_H
