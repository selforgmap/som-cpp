#include "main.h"

#include <iostream>
#include <vector>

#include "init.h"
#include "utils/arg_parser.h"

#include "utils/csv_loader.h"
#include "core/som.h"
#include "grids/rectangular.h"

#include "helpers/trainer_helper.h"
#include "struct/node.h"

using namespace std;

int main(int argc, char** argv) {

    // Create som
    SOM som;

    // Configurations
    parse_config_from_args(som, argc, argv);

    cout << som.grid->ToString() << endl;

    // Load dataset from file
    vector<vector<double> > input_space = load_csv(DEFAULT_INPUT_FILE_PATH);

    // Train
    som.Train(input_space);
    cout << som.grid->ToString();

    return 0;
}
