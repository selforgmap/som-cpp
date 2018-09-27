//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#ifndef SOM_MATH_HELPER_H
#define SOM_MATH_HELPER_H

#include "../struct/position.h"

namespace utils {

/**
 * Get Euclidean distance of two points
 * @param pos1 Position of neurone 1
 * @param pos2 Position of neurone 2
 * @return Euclidean distance between neurones
 */
double euclidean_distance(Position pos1, Position pos2);

} // namespace utils

#endif //SOM_MATH_HELPER_H
