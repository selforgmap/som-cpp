#include "main.h"

#include <iostream>
#include <vector>

#include "config.h"
#include "utils/csv_loader.h"
#include "core/trainer.h"
#include "grid/rectangular.h"

#include "utils/trainer_helper.h"

using namespace std;

int main() {
    // New trainer session
    trainer trainer;

    // Load dataset
    trainer.input_vector = load_csv(INPUT_PATH);

    // Create new grid
    trainer.grid = new Rectangular(10, 10, 3);

    // Initialize random weights
    initialize_random_weights(trainer.grid);


    for (vector<int> neu : trainer.grid->neurones){
        for (int w : neu){
            cout << w << endl;
        }
    }

    std::cout << "Program is running..." << std::endl;
    return 0;
}
