#include "../etl/include/etl/array.h"
#include "../etl/include/etl/algorithm.h"
#include <iostream>
#include <chrono>

int main() {
    etl::array<int, 100> source;
    etl::array<int, 100> destination;

    // Fill the source array
    for (int i = 0; i < 100; ++i) {
        source[i] = i;
    }

    auto start = std::chrono::high_resolution_clock::now();
    etl::move(source.begin(), source.end(), destination.begin());
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "ETL move operation duration: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
