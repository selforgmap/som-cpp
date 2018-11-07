//
// Created by Sumedhe Dissanayake on 9/24/18.
//

#include "csv_loader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "../struct/dataitem.h"

using namespace std;

vector<DataItem> load_csv(string filename){
    // Load file
    ifstream data(filename);
    string line;
    vector<DataItem> dataset;

    // Read lines
    while(std::getline(data,line)) {
        stringstream line_stream(line);
        string cell;
        DataItem dataitem;
        while(getline(line_stream, cell, ','))
        {
            dataitem.features.push_back(stof(cell));
        }

        dataset.push_back(dataitem);
    }

    // Print error
    if (errno) {
        cout << strerror(errno) << endl;
    }

    return dataset;

}
