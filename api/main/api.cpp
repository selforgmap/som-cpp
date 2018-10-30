//
// Created by Sumedhe Dissanayake on 11/5/18.
//

#include "api.h"


#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

#include "../../src/core/trainer.h"
#include "../../src/struct/config.h"
#include "../../src/helpers/learning_rate.h"
#include "../../src/utils/csv_loader.h"
#include "../../src/init.h"

using namespace std;

// Start training
string start_training(){
    // Configurations
    Config config;
    
    // Create trainer
    Trainer trainer(config);
    cout << trainer.grid->ToString() << endl;

    // Load dataset from file
    vector<vector<float> > input_space;
    vector<float> data1 = {1,1,1};
    input_space.push_back(data1);

    // Train
    trainer.Train(input_space);
    return trainer.grid->ToString();
}

BOOST_PYTHON_MODULE(api)
{
    using namespace boost::python;

    def("startTraining", start_training);
}
