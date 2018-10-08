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
    // New trainer session
    Trainer trainer;

    // Load dataset
    trainer.input_space = load_csv(INPUT_PATH);

    // Create new grid
    trainer.grid = new Rectangular(10, 10, 3);
    trainer.grid->InitializeNodes();

    // Initialize random weights
    initialize_random_weights(trainer.grid);


    std::cout << "Program is running..." << std::endl;
    return 0;
}
