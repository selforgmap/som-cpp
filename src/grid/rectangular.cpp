//
// Created by Sumedhe Dissanayake on 10/3/18.
//

#include "rectangular.h"

#include "../struct/position.h"
#include "../utils/math_helper.h"


Rectangular::Rectangular(int width, int height, int dimention, bool random_initialization) : Grid(width, height, dimention, random_initialization) { }

Position Rectangular::GetPosition(int neurone_index) {
    Position pos;
    pos.x = neurone_index % this->width;
    pos.y = (int)(neurone_index / this->width);


    return pos;
}
