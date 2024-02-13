#include "../etl/include/etl/vector.h"
#include "../etl/include/etl/algorithm.h"
#include <iostream>
#include <chrono>

int main() {
    etl::vector<int, 100> numbers; // Static allocation with a fixed size of 100

    // Fill the vector
    for (int i = 0; i < 100; ++i) {
        numbers.push_back(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto result = etl::find(numbers.begin(), numbers.end(), 50); // Find number 50
    auto end = std::chrono::high_resolution_clock::now();

    if (result != numbers.end()) {
        std::cout << "Found " << *result << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "ETL find duration: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
