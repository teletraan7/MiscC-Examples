#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void thread1() {
    // Attempt to lock the first mutex
    std::cout << "Thread 1: Trying to lock mutex1" << std::endl;
    mutex1.lock();
    std::cout << "Thread 1: Locked mutex1" << std::endl;

    // Simulate some work by sleeping
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Attempt to lock the second mutex
    std::cout << "Thread 1: Trying to lock mutex2" << std::endl;
    mutex2.lock();
    std::cout << "Thread 1: Locked mutex2" << std::endl;

    // Critical section
    std::cout << "Thread 1: In critical section" << std::endl;

    // Unlock the mutexes
    mutex2.unlock();
    mutex1.unlock();
}

void thread2() {
    // Attempt to lock the second mutex
    std::cout << "Thread 2: Trying to lock mutex2" << std::endl;
    mutex2.lock();
    std::cout << "Thread 2: Locked mutex2" << std::endl;

    // Simulate some work by sleeping
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Attempt to lock the first mutex
    std::cout << "Thread 2: Trying to lock mutex1" << std::endl;
    mutex1.lock();
    std::cout << "Thread 2: Locked mutex1" << std::endl;

    // Critical section
    std::cout << "Thread 2: In critical section" << std::endl;

    // Unlock the mutexes
    mutex1.unlock();
    mutex2.unlock();
}

int main() {
    // EXAMPLE OF A DEADLOCK
    // A DEADLOCK IS WHEN MULTIPLE THREADS ARE BEING BLOCKED FROM CONTINUING BECAUSE EACH IS WAITING FOR RESOURCES HELD BY ANOTHER THREAD.

    // Create two threads
    std::thread t1(thread1);
    std::thread t2(thread2);

    //BOTH THREADS WILL ATTEMPT TO LOCK AND USE BOTH MUTEX, THIS WILL CAUSE A DEADLOCK WHILE EACH WAITS FOR THE OTHER TO FREE UP THE OTHER MUTEX.

    // Wait for the threads to finish
    t1.join();
    t2.join();

    return 0;
}
