#include "main.h"

#include <iostream>
#include <vector>

#include "config.h"
#include "utils/csv_loader.h"
#include "core/trainer.h"
#include "grids/rectangular.h"

#include "helpers/trainer_helper.h"
#include "struct/node.h"

using namespace std;

int main() {

    // Parameters
    int x_dim           = 10;
    int y_dim           = 10;
    int dimention       = 3;
    int iteration_limit = 10;
    float learning_rate = 0.4;

    // Load dataset
    vector<vector<float>> input_space = load_csv(INPUT_PATH);

    // Create new grids
    Grid* grid = new Rectangular(x_dim, y_dim, dimention);
    grid->InitializeNodes();

    // Initialize random weights
    initialize_random_weights(grid);

    // New trainer session
    Trainer trainer(grid, input_space, iteration_limit, learning_rate);

    cout << grid->ToString();

    trainer.Train();

    std::cout << "Program is running..." << std::endl;
    return 0;
}
