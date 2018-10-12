#include "main.h"

#include <iostream>
#include <vector>

#include "config.h"
#include "utils/csv_loader.h"
#include "core/trainer.h"
#include "grid/rectangular.h"

#include "utils/trainer_helper.h"
#include "struct/node.h"

using namespace std;

int main() {
    // Load dataset
    vector<vector<float>> input_space = load_csv(INPUT_PATH);

    // Create new grid
    Grid* grid = new Rectangular(10, 10, 3);
    grid->InitializeNodes();

    // Initialize random weights
    initialize_random_weights(grid);

    int iterations      = 100;
    int initial_radius  = 10;
    float learning_rate = 0.4;

    // New trainer session
    Trainer trainer(grid, input_space, iterations, learning_rate, initial_radius);

    cout << grid->ToString();

    std::cout << "Program is running..." << std::endl;
    return 0;
}
