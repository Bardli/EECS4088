#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> numbers;

    // Fill the vector
    for (int i = 99; i >= 0; --i) {
        numbers.push_back(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto minIt = std::min_element(numbers.begin(), numbers.end());
    auto end = std::chrono::high_resolution_clock::now();

    if (minIt != numbers.end()) {
        std::cout << "Minimum element: " << *minIt << std::endl;
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "STL min_element duration: " << duration.count() << " microseconds." << std::endl;

    return 0;
}
