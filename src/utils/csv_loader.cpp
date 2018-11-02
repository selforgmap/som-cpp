//
// Created by Sumedhe Dissanayake on 9/24/18.
//

#include "csv_loader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<double> > load_csv(string filename){
    // Load file
    ifstream data(filename);
    string line;
    vector<vector<double> > dataset;

    // Read lines
    while(std::getline(data,line))
    {
        stringstream line_stream(line);
        string cell;
        vector<double> parsed_row;
        while(getline(line_stream, cell, ','))
        {
            parsed_row.push_back(stof(cell));
        }

        dataset.push_back(parsed_row);
    }

    // Print error
    if (errno) {
        cout << strerror(errno) << endl;
    }

    return dataset;

}
