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
#include "../../src/struct/dataitem.h"

using namespace std;

// Python module definitons
BOOST_PYTHON_MODULE(som)
{
    using namespace boost::python;

    class_<Session>("Session")
            .def("Initialize",                          &Session::Initialize)
            .def("Train",                               &Session::Train)
            .def("GetResult",                           &Session::GetResult)
            .add_property("x_dim",                      &Session::GetXDim, &Session::SetXDim)
            .add_property("y_dim",                      &Session::GetYDim, &Session::SetYDim)
            .add_property("dimension",                  &Session::GetDimension, &Session::SetDimension)
            .add_property("grid_type",                  &Session::GetGridType, &Session::SetGridType)
            .add_property("itereation_limit",           &Session::GetIterationLimit, &Session::SetIterationLimit)
            .add_property("starting_learning_rate",     &Session::GetStartingLearningRate, &Session::SetStartingLearningRate)
            .add_property("node_initialization_method", &Session::GetNodeInitializationMethod, &Session::SetNodeInitializationMethod)
            .add_property("learning_rate_type",         &Session::GetLearningRateType, &Session::SetLearningRateType)
            .add_property("neighborhood_type",          &Session::GetNeighborhoodType, &Session::SetNeighborhoodType)
            .add_property("min_node_weight",            &Session::GetMinNodeWeight, &Session::SetMinNodeWeight)
            .add_property("max_node_weight",            &Session::GetMaxNodeWeight, &Session::SetMaxNodeWeight);
}

Session::Session() : som() {

}


void Session::Initialize(){
    this->som.Initialize();
}

void Session::Train(boost::python::list& data){

    // Load dataset
    vector<DataItem> dataset = list_matrix_to_dataset(data);

    // Train
    som.Train(dataset);

}


boost::python::list Session::GetResult(){
    return double_matrix_to_list_matrix(this->som.grid->GetWeightMatrix());
}


int Session::GetXDim(){
    return this->som.x_dim;
}

void Session::SetXDim(int value){
    this->som.x_dim = value;
}


int Session::GetYDim(){
    return this->som.y_dim;
}

void Session::SetYDim(int value){
    this->som.y_dim = value;
}


int Session::GetDimension(){
    return this->som.dimension;
}

void Session::SetDimension(int value){
    this->som.dimension = value;
}


string Session::GetGridType(){
    return this->som.grid_type;
}

void Session::SetGridType(string value){
    this->som.grid_type = value;
}


int Session::GetIterationLimit(){
    return this->som.iteration_limit;
}

void Session::SetIterationLimit(int value){
    this->som.iteration_limit = value;
}


float Session::GetStartingLearningRate(){
    return this->som.starting_learning_rate;
}

void Session::SetStartingLearningRate(float value){
    this->som.starting_learning_rate = value;
}


string Session::GetNodeInitializationMethod(){
    return this->som.node_initialization_method;
}

void Session::SetNodeInitializationMethod(string value){
    this->som.node_initialization_method = value;
}


string Session::GetLearningRateType(){
    return ""; // TODO: Return value as string
}

void Session::SetLearningRateType(string value){
    this->som.learning_rate_type = LearningRate::type_map[value];
}


string Session::GetNeighborhoodType(){
    return ""; // TODO: Return value as string
}

void Session::SetNeighborhoodType(string value){
    this->som.neighborhood_type = Neighborhood::type_map[value];
}


float Session::GetMinNodeWeight(){
    return this->som.min_node_weight;
}

void Session::SetMinNodeWeight(float value){
    this->som.min_node_weight = value;
}


float Session::GetMaxNodeWeight(){
    return this->som.max_node_weight;
}

void Session::SetMaxNodeWeight(float value){
    this->som.max_node_weight = value;
}



