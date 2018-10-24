#include "main.h"

#include <iostream>
#include <vector>

#include "init.h"
#include "struct/config.h"
#include "utils/arg_parser.h"

#include "utils/csv_loader.h"
#include "core/trainer.h"
#include "grids/rectangular.h"

#include "helpers/trainer_helper.h"
#include "struct/node.h"

using namespace std;

int main(int argc, char** argv) {

    // Configurations
    Config config = argsToConfig(argc, argv);

    // Create trainer
    Trainer trainer(config);
    cout << trainer.grid->ToString() << endl;

    // Load dataset from file
    vector<vector<float>> input_space = load_csv(config.input_file_path);

    // Train
    trainer.Train(input_space);
    cout << trainer.grid->ToString();

    return 0;
}
