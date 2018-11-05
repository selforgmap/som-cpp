//
// Created by Sumedhe Dissanayake on 11/6/18.
//

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <vector>

#ifndef SOM_SESSION_HELPER_H
#define SOM_SESSION_HELPER_H

using namespace std;

/**
 * Convert python list matrix to cpp double matrix
 * @param data Python list matrix
 * @return Double matrix
 */
vector<vector<double> > list_matrix_to_double_matrix(boost::python::list &data);

/**
 * Convert cpp double matrix to python list matrix
 * @param data Double matrix
 * @return Python list matrix
 */
boost::python::list double_matrix_to_list_matrix(<vector<vector<double> > &data);

#endif //SOM_SESSION_HELPER_H
