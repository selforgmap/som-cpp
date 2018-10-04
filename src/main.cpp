#include "main.h"

#include <iostream>
#include <vector>

#include "config.h"
#include "utils/csv_loader.h"
#include "core/trainer.h"
#include "grid/rectangular.h"

using namespace std;

int main() {
    // New trainer session
    trainer trainer;

    // Load dataset
    trainer.dataset = utils::load_csv(INPUT_PATH);

    // Create new grid
    trainer.grid = new Rectangular(10, 10);

    std::cout << "Program is running..." << std::endl;
    return 0;
}
