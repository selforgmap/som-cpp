//
// Created by Sumedhe Dissanayake on 9/24/18.
//

#include "csv_loader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace utils {

// Load CSV file
vector<vector<string>> load_csv(string filename){
    // Load file
    ifstream data(filename);
    string line;
    vector<vector<string>> dataset;

    // Read lines
    while(std::getline(data,line))
    {
        stringstream line_stream(line);
        string cell;
        vector<string> parsed_row;
        while(std::getline(line_stream, cell, ','))
        {
            parsed_row.push_back(cell);
        }

        dataset.push_back(parsed_row);
    }

    return dataset;

}

} // namespace utils