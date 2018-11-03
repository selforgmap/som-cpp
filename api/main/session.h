//
// Created by Sumedhe Dissanayake on 11/5/18.
//

#ifndef SOM_API_H
#define SOM_API_H

#include <string>
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <vector>
#include "../../src/core/som.h"
#include "../../src/struct/config.h"

class Session {
public:
    Config config;
    SOM som;

    Session(){

    }

    string Train(boost::python::list& data);

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

private:
    vector<vector<double> > ParseInputSpace(boost::python::list& data);


};

std::string start_training();

#endif //SOM_API_H
