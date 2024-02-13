#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> myVector;

    // Populate the vector.
    myVector.push_back(3);
    myVector.push_back(1);
    myVector.push_back(4);
    myVector.push_back(1);
    myVector.push_back(5);
    myVector.push_back(9);
    myVector.push_back(2);
    myVector.push_back(6);
    myVector.push_back(5);
    myVector.push_back(3);

    std::cout << "Original vector:\n";
    for (int i : myVector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Start the timer.
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the vector using std::sort.
    std::sort(myVector.begin(), myVector.end());

    // Stop the timer.
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate the duration.
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Sorted vector:\n";
    for (int i : myVector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::cout << "Time taken to sort: " << duration.count() << " microseconds.\n";

    return 0;
}
