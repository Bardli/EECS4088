#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> heap;

    // Fill the heap
    for (int i = 0; i < 100; ++i) {
        heap.push_back(i);
        std::push_heap(heap.begin(), heap.end());
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::pop_heap(heap.begin(), heap.end());
    heap.pop_back();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "STL heap operation duration: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
