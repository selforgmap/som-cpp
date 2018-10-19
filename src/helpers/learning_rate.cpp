//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#include "learning_rate.h"

#include <math.h>

float constant_learning_rate(float starting_learning_rate){
    return starting_learning_rate;
}

float linear_learning_rate(float starting_learning_rate, int iteration){
    return 1.0f * starting_learning_rate * (1 / 1.0f * iteration);
}

float inverse_of_time_learning_rate(float starting_learning_rate, int iteration, int iteration_limit){
    return starting_learning_rate * (1 - iteration / 1.0f * iteration_limit);
}

float power_series_learning_rate(float starting_learning_rate, int iteration, int iteration_limit){
    return (float)(starting_learning_rate * exp(iteration / iteration_limit));
}