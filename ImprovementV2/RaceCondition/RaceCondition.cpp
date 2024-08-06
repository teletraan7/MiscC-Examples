#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

// Global counter
int counter = 0;

// Function to be executed by each thread
void incrementCounter() {
    for (int i = 0; i < 1000; ++i) {
        // Increment the counter
        // This is where the race condition happens as multiple threads are reading, incrementing, and writing counter at once.
        // To fix we could mutex lock counter
        ++counter;
    }
}

int main() {
    // Vector to hold our threads
    std::vector<std::thread> threads;

    // Create and start 10 threads
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(incrementCounter));
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    // Print the final value of the counter
    // Due to the race condition the value could be less than the expected 10,000.
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}