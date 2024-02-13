#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> numbers;

    // Fill the vector
    for (int i = 0; i < 100; ++i) {
        numbers.push_back(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto result = std::find(numbers.begin(), numbers.end(), 50); // Find number 50
    auto end = std::chrono::high_resolution_clock::now();

    if (result != numbers.end()) {
        std::cout << "Found " << *result << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "STL find duration: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
