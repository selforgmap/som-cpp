//
// Created by Sumedhe Dissanayake on 11/5/18.
//

#include "session.h"


#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

#include "session_helper.h"
#include "../../src/core/som.h"
#include "../../src/struct/config.h"
#include "../../src/helpers/learning_rate.h"
#include "../../src/utils/csv_loader.h"
#include "../../src/init.h"

using namespace std;

// Python module definitons
BOOST_PYTHON_MODULE(api)
{
    using namespace boost::python;

    class_<Session>("Session")
            .def("Train",                       &Session::Train)
            .def("SetXDim",                     &Session::SetXDim)
            .def("SetYDim",                     &Session::SetYDim)
            .def("SetDimension",                &Session::SetDimension)
            .def("SetGridType",                 &Session::SetGridType)
            .def("SetIterationLimit",           &Session::SetIterationLimit)
            .def("SetStartingLearningRate",     &Session::SetStartingLearningRate)
            .def("SetNodeInitializationMethod", &Session::SetNodeInitializationMethod)
            .def("SetLearningRateType",         &Session::SetLearningRateType)
            .def("SetNeighborhoodType",         &Session::SetNeighborhoodType)
            .def("SetMinNodeWeight",            &Session::SetMinNodeWeight)
            .def("SetMaxNodeWeight",            &Session::SetMaxNodeWeight);
}


string Session::Train(boost::python::list& data){

    // Create som trainer
    SOM som(this->config);
    cout << som.grid->ToString() << endl;

    // Load dataset
    vector<vector<double> > input_space = list_matrix_to_double_matrix(data);

    // Train
    som.Train(input_space);
    return som.grid->ToString();

}



void Session::SetXDim(int value){
    this->config.x_dim = value;
}

void Session::SetYDim(int value){
    this->config.y_dim = value;
}

void Session::SetDimension(int value){
    this->config.dimension = value;
}

void Session::SetGridType(string value){
    this->config.grid_type = value;
}

void Session::SetIterationLimit(int value){
    this->config.iteration_limit = value;
}

void Session::SetStartingLearningRate(float value){
    this->config.starting_learning_rate = value;
}

void Session::SetNodeInitializationMethod(string value){
    this->config.node_initialization_method = value;
}

void Session::SetLearningRateType(string value){
    this->config.learning_rate_type = LearningRate::type_map[value];
}

void Session::SetNeighborhoodType(string value){
    this->config.neighborhood_type = Neighborhood::type_map[value];
}

void Session::SetMinNodeWeight(float value){
    this->config.min_node_weight = value;
}

void Session::SetMaxNodeWeight(float value){
    this->config.max_node_weight = value;
}



