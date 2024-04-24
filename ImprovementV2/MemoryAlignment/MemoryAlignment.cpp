#include <iostream>
#include <chrono>

// Define a simple structure representing a point in 2D space
struct Point {
    float x;
    float y;
};

int main() {
    // Step 1: Create instances of the structure with and without padding
    Point alignedPoint {};
    
    // Define an unaligned structure with padding to make it unaligned
    struct UnalignedPoint {
        float x;
        char padding; // Introduce padding to make it unaligned
        float y;
    } unalignedPoint {};

    // Step 2: Print the size of each structure
    std::cout << "Size of aligned Point: " << sizeof(alignedPoint) << " bytes" << std::endl;
    std::cout << "Size of unaligned Point: " << sizeof(unalignedPoint) << " bytes" << std::endl;

    // Step 3: Demonstrate the impact on performance

    // Create a constant for the number of iterations
    constexpr int numIterations = 1'000'000;

    // Aligned Point Calculation
    {
        // Measure the start time
        auto start = std::chrono::high_resolution_clock::now();

        // Perform a simple calculation using an instance of aligned Point
        for (int i = 0; i < numIterations; ++i) {
            alignedPoint.x += 1.0;
            alignedPoint.y += 1.0;
        }

        // Measure the end time
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate and print the time taken for aligned Point calculation
        std::cout << "Time for aligned Point calculation: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds"
                  << std::endl;
    }

    // Unaligned Point Calculation
    {
        // Measure the start time
        auto start = std::chrono::high_resolution_clock::now();

        // Perform a simple calculation using an instance of unaligned Point
        for (int i = 0; i < numIterations; ++i) {
            unalignedPoint.x += 1.0;
            unalignedPoint.y += 1.0;
        }

        // Measure the end time
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate and print the time taken for unaligned Point calculation
        std::cout << "Time for unaligned Point calculation: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds"
                  << std::endl;
    }

    return 0;
}