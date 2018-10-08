//
// Created by Sumedhe Dissanayake on 10/3/18.
//

#include "rectangular.h"

#include "../utils/math_helper.h"

Rectangular::Rectangular(int x_dim, int y_dim, int dimention, bool random_initialization) : Grid(x_dim, y_dim, dimention, random_initialization) { }

pair<float, float> Rectangular::CalculateLocation(int node_index){
    pair<float, float> loc;
    loc = make_pair(node_index % this->x_dim, node_index / this->x_dim);
    return loc;
}

