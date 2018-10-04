//
// Created by Sumedhe Dissanayake on 10/3/18.
//

#include "rectangular.h"

#include "../struct/position.h"
#include "../utils/math_helper.h"


Rectangular::Rectangular(int width, int height) {
    this->width          = width;
    this->height         = height;
    this->no_of_neurones = width * height;
}

Position Rectangular::GetPosition(int neurone_index) {
    Position pos;
    pos.x = neurone_index % this->width;
    pos.y = (int)(neurone_index / this->width);
    return pos;
}
