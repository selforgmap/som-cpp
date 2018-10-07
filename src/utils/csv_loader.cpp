//
// Created by Sumedhe Dissanayake on 9/24/18.
//

#include "csv_loader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> load_csv(string filename){
    // Load file
    ifstream data(filename);
    string line;
    vector<vector<int>> dataset;

    // Read lines
    while(std::getline(data,line))
    {
        stringstream line_stream(line);
        string cell;
        vector<int> parsed_row;
        while(std::getline(line_stream, cell, ','))
        {
            parsed_row.push_back(stoi(cell));
        }

        dataset.push_back(parsed_row);
    }

    // Print error
    if (errno) {
        cout << strerror(errno) << endl;
    }

    return dataset;

}
