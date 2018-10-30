//
// Created by Sumedhe Dissanayake on 10/3/18.
//
#include<string>
//#include "helpers/learning_rate.h"
//#include "helpers/neighborhood.h"

using namespace std;

#ifndef SOM_INIT_H
#define SOM_INIT_H


#include "helpers/learning_rate.h"
#include "helpers/neighborhood.h"

// App config
const int    DEFAULT_X_DIM                      = 10;
const int    DEFAULT_Y_DIM                      = 10;
const int    DEFUALT_DIMENSION                  = 3;
const string DEFAULT_GRID_TYPE                  = "RECTANGULAR";
const int    DEFAULT_ITERATION_LIMIT            = 100;
const float  DEFAULT_STARTING_LEARNING_RATE     = 0.4;
const string DEFAULT_NODE_INITIALIZATION_METHOD = "RANDOM";
const LearningRate::type DEFAULT_LEARNING_RATE_TYPE = LearningRate::LR_CONSTANT;
const Neighborhood::type DEFAULT_NEIGHBORHOOD_TYPE  = Neighborhood::NF_BUBBLE;
const int    DEFAULT_MIN_NODE_WEIGHT            = 1;
const int    DEFAULT_MAX_NODE_WEIGHT            = 99;
const string DEFAULT_INPUT_FILE_PATH            = "../../resources/input.csv";

#endif //SOM_INIT_H
