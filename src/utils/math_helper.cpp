//
// Created by Sumedhe Dissanayake on 10/4/18.
//

#include "math_helper.h"

#include <cmath>

using namespace std;

float euclidean_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
