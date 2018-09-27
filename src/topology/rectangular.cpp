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

Position Rectangular::GetPosition(int neurone_index, Rectangular rect) {
    Position position;
    position.x = neurone_index % rect.width;
    position.y = (int)(neurone_index / rect.width);
    return position;
}

double Rectangular::GetDistance(int neurone1, int neurone2, Rectangular rect) {
    Position pos1 = Rectangular::GetPosition(neurone1, rect);
    Position pos2 = Rectangular::GetPosition(neurone2, rect);
    return utils::euclidean_distance(pos1, pos2);
}