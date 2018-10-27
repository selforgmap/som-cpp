//
// Created by Sumedhe Dissanayake on 10/18/18.
//

#include "learning_rate.h"

#include <iostream>
#include <cmath>

using namespace std;

std::map<std::string, LearningRate::type> LearningRate::type_map = {
        { "CONSTANT",        LR_CONSTANT },
        { "LINEAR",          LR_LINEAR },
        { "INVERSE_OF_TIME", LR_INVERSE_OF_TIME },
        { "POWER_SERIES",    LR_POWER_SERIES }
};

float LearningRate::Calculate(LearningRate::type type, float starting_learning_rate, int iteration, int iteration_limit) {
    switch (type){
        case LR_CONSTANT:
            return LearningRate::ConstantLearningRate(starting_learning_rate);
        case LR_LINEAR:
            return LearningRate::LinearLearningRate(starting_learning_rate, iteration);
        case LR_INVERSE_OF_TIME:
            return LearningRate::InverseOfTimeLearningRate(starting_learning_rate, iteration, iteration_limit);
        case LR_POWER_SERIES:
            return LearningRate::PowerSeriesLearningRate(starting_learning_rate, iteration, iteration_limit);
    }
}

float LearningRate::ConstantLearningRate(float starting_learning_rate) {
    return starting_learning_rate;
}

float LearningRate::LinearLearningRate(float starting_learning_rate, int iteration){
    return 1.0f * starting_learning_rate * (1 / 1.0f * iteration);
}

float LearningRate::InverseOfTimeLearningRate(float starting_learning_rate, int iteration, int iteration_limit){
    return starting_learning_rate * (1 - iteration / 1.0f * iteration_limit);
}

float LearningRate::PowerSeriesLearningRate(float starting_learning_rate, int iteration, int iteration_limit){
    return (float)(starting_learning_rate * exp(iteration / iteration_limit));
}