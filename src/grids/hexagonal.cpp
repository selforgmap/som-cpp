//
// Created by Sumedhe Dissanayake on 12/20/18.
//

#include "hexagonal.h"
Hexagonal::Hexagonal(int x_dim, int y_dim, int dimention, bool random_initialization) : Grid(x_dim, y_dim, dimention, random_initialization) { }

pair<float, float> Hexagonal::CalculateLocation(int node_index){
    pair<float, float> loc;
    loc = make_pair(node_index % this->x_dim, node_index / this->x_dim); // TODO: Distance in hexagonal grid
    return loc;
}
