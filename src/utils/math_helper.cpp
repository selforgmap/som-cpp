//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include "math_helper.h"

#include <cmath>

using namespace std;

float euclidean_distance(Position pos1, Position pos2) {
    return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}
