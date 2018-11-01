//
// Created by Sumedhe Dissanayake on 11/5/18.
//

#ifndef SOM_API_H
#define SOM_API_H

#include <string>
#include "../../src/core/som.h"
#include "../../src/struct/config.h"

class Session {
public:
    Config config;
    SOM som;

    Session(){

    }

    string Train();

    void SetXDim(int value);

    void SetYDim(int value);

    void SetDimension(int value);

    void SetGridType(string value);

    void SetIterationLimit(int value);

    void SetStartingLearningRate(float value);

    void SetNodeInitializationMethod(string value);

    void SetLearningRateType(string value);

    void SetNeighborhoodType(string value);

    void SetMinNodeWeight(float value);

    void SetMaxNodeWeight(float value);

};

std::string start_training();

#endif //SOM_API_H
