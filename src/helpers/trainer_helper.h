//
// Created by Sumedhe Dissanayake on 10/6/18.
//

#ifndef SOM_TRAINER_HELPER_H
#define SOM_TRAINER_HELPER_H

#include "../init.h"

#include "../core/grid.h"

/**
 * Initialize neurones with random weights
 * @param grid Grid
 * @param min Min value of weight
 * @param max Max value of weight
 * @return Neurone set with random weights
 */
void initialize_random_weights(
        Grid* grid,
        int min,
        int max);

/**
 * Calculate the euclidean distance between two vectors
 * @param input_vector Input vector
 * @param weight_vector Weight vector
 * @return Squared euclidean distance
 */
float squared_euclidean_distance(vector<float> input_vector, vector<float> weight_vector);

/**
 * Get Euclidean distance of two points
 * @param x1 X coordinate of point 1
 * @param y1 Y coordinate of point 1
 * @param x2 X coordinate of point 2
 * @param y2 Y coordinate of point 2
 * @return Distance between two points
 */
float euclidean_distance(float x1, float y1, float x2, float y2);

#endif //SOM_TRAINER_HELPER_H
