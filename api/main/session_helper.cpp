//
// Created by Sumedhe Dissanayake on 11/6/18.
//

#include "session_helper.h"

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <vector>

#include "../../src/struct/dataitem.h"

vector<DataItem> list_matrix_to_dataset(boost::python::list &data){
    vector<DataItem> dataset;

    for (int i = 0; i < len(data); ++i) {
        DataItem dataitem;
        for (int j = 0; j < len(data[i]); j++){
            dataitem.features.push_back(boost::python::extract<double>(data[i][j]));
        }
        dataset.push_back(dataitem);
    }

    return dataset;
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