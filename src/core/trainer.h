//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include <vector>

#include "../grid/grid.h"

#ifndef SOM_TRAINER_H
#define SOM_TRAINER_H

/**
 * Trainer class
 */
class Trainer {
public:
    std::vector<std::vector<float>> input_space;
    Grid* grid;
};

#endif //SOM_TRAINER_H
