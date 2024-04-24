#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex m{};

class NString
{
public:
    NString(const std::string& string) : data(string)
    {
    }

    void Print() const
    {
        std::lock_guard<std::mutex> lock(m);
        for (char i : data)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }

private:
    std::string data;
};

void CreateNString(const std::string& oldString, float multi)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long>(multi * 5000)));
    NString threadString(oldString);
    threadString.Print();
}

int main()
{
    std::string first = "First";
    std::thread t1 {CreateNString, first, 1.0};
    std::cout << "The first original string: " << first << "\n";
    std::thread t2 {CreateNString, "Second", .25};
    t1.join();
    t2.join();
    std::thread t3 {CreateNString, "Third", 2.0};
    std::thread t4 {CreateNString, "Fourth", 2.0};
    std::thread t5 {CreateNString, "Fifth", 2.0};
    t3.join();
    t4.join();
    t5.join();
    printf("Press Enter to End \n");
    std::cin.get();
}
