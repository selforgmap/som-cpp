#include "main.h"

#include <iostream>
#include <vector>

#include "init.h"
#include "struct/config.h"
#include "utils/arg_parser.h"

#include "utils/csv_loader.h"
#include "core/som.h"
#include "grids/rectangular.h"

#include "helpers/trainer_helper.h"
#include "struct/node.h"

using namespace std;

int main(int argc, char** argv) {

    // Configurations
    Config config = argsToConfig(argc, argv);

    // Create som
    SOM som(config);
    cout << som.grid->ToString() << endl;

    // Load dataset from file
    vector<vector<float>> input_space = load_csv(config.input_file_path);

    // Train
    som.Train(input_space);
    cout << som.grid->ToString();

    return 0;
}
