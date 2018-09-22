#include <iostream>
#include <vector>
#include <fstream>
#include "config.h"
#include "utils/csv_loader.h"

using namespace std;

int main() {
    std::cout << "Program is running..." << std::endl;
    if (errno) cerr << "Error: " << strerror(errno);
    return 0;
}