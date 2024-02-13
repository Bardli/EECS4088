#include "../etl/include/etl/vector.h"
#include "../etl/include/etl/algorithm.h"
#include <iostream>
#include <chrono>

int main() {
    etl::vector<int, 100> numbers; // Static allocation with a fixed size of 100

    // Fill the vector
    for (int i = 99; i >= 0; --i) {
        numbers.push_back(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto minIt = etl::min_element(numbers.begin(), numbers.end());
    auto end = std::chrono::high_resolution_clock::now();

    if (minIt != numbers.end()) {
        std::cout << "Minimum element: " << *minIt << std::endl;
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "ETL min_element duration: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
