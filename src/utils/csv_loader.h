//
// Created by Sumedhe Dissanayake on 9/24/18.
//

#include <iostream>
#include <vector>
#include <fstream>

#ifndef SOM_CSV_PARSER_H
#define SOM_CSV_PARSER_H

/**
 * Load CSV file to a vector
 * @param filename Filename/Path of the CSV file
 * @return Vector of the dataset
 */
std::vector<std::vector<double> > load_csv(std::string filename);

#endif //SOM_CSV_PARSER_H
