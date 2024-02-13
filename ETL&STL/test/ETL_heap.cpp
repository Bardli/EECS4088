// Pseudo-code as ETL does not directly support heap operations
#include "../etl/include/etl/vector.h"
#include "../etl/include/etl/algorithm.h"
#include <iostream>
#include <chrono>

int main() {
    etl::vector<int, 100> heap;

    // Fill the heap
    for (int i = 0; i < 100; ++i) {
        heap.push_back(i);
    }
    etl::make_heap(heap.begin(), heap.end());

    auto start = std::chrono::high_resolution_clock::now();
    etl::pop_heap(heap.begin(), heap.end());
    heap.pop_back();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "ETL heap operation duration: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
