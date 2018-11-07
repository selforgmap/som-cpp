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
#include "../../src/helpers/learning_rate.h"
#include "../../src/utils/csv_loader.h"

using namespace std;

// Python module definitons
BOOST_PYTHON_MODULE(som)
{
    using namespace boost::python;

    class_<Session>("Session")
            .def("Train",                       &Session::Train)
            .def("GetResult",                   &Session::GetResult)
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

Session::Session() : som() {

}

void Session::Train(boost::python::list& data){

    // Create som trainer
    cout << this->som.grid->ToString() << endl;

    // Load dataset
    vector<vector<double> > dataset = list_matrix_to_double_matrix(data);

    // Train
    som.Train(dataset);

}


boost::python::list Session::GetResult(){
    return double_matrix_to_list_matrix(this->som.grid->GetWeightMatrix());
}


void Session::SetXDim(int value){
    this->som.x_dim = value;
}

void Session::SetYDim(int value){
    this->som.y_dim = value;
}

void Session::SetDimension(int value){
    this->som.dimension = value;
}

void Session::SetGridType(string value){
    this->som.grid_type = value;
}

void Session::SetIterationLimit(int value){
    this->som.iteration_limit = value;
}

void Session::SetStartingLearningRate(float value){
    this->som.starting_learning_rate = value;
}

void Session::SetNodeInitializationMethod(string value){
    this->som.node_initialization_method = value;
}

void Session::SetLearningRateType(string value){
    this->som.learning_rate_type = LearningRate::type_map[value];
}

void Session::SetNeighborhoodType(string value){
    this->som.neighborhood_type = Neighborhood::type_map[value];
}

void Session::SetMinNodeWeight(float value){
    this->som.min_node_weight = value;
}

void Session::SetMaxNodeWeight(float value){
    this->som.max_node_weight = value;
}



