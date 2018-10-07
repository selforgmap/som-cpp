//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#ifndef SOM_TRAINER_HELPER_H
#define SOM_TRAINER_HELPER_H

#include "../config.h"

#include "../grid/grid.h"

/**
 * Initialize neurones with random weights
 * @param grid Grid
 * @param min Min value of weight
 * @param max Max value of weight
 * @return Neurone set with random weights
 */
void initialize_random_weights(
        Grid* grid,
        int min = DEFAULT_MIN_WEIGHT,
        int max = DEFAULT_MAX_WEIGHT);

#endif //SOM_TRAINER_HELPER_H
