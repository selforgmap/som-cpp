//
// Created by Sumedhe Dissanayake on 11/6/18.
//

#include "session_helper.h"

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <vector>

vector<vector<double> > list_matrix_to_double_matrix(boost::python::list &data){
    vector<vector<double> > matrix;

    for (int i = 0; i < len(data); ++i) {
        vector<double> item;
        for (int j = 0; j < len(data[i]); j++){
            item.push_back(boost::python::extract<double>(data[i][j]));
        }
        matrix.push_back(item);
    }

    return matrix;
}

boost::python::list double_matrix_to_list_matrix(vector<vector<double> > data){
    boost::python::list matrix;

    for (int i = 0; i < data.size(); ++i) {
        boost::python::list item;
        for (int j = 0; j < data[i].size(); j++){
            item.append(data[i][j]);
        }
        matrix.append(item);
    }

    return matrix;
}