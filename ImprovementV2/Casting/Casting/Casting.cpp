// Casting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#pragma region Dynamic
class Foo
{
public:
    virtual void print()
    {
        std::cout << "Base" << std::endl;
    }
};

class Bar : public Foo
{
public:
    void print()
    {
        std::cout << "Derived" << std::endl;
    }

    void Test()
    {
        std::cout << "Test" << std::endl;
    }
};
#pragma endregion

#pragma region Const
int TimesTen(int* ptr)
{
    return *ptr * 10;
}
#pragma endregion

int main()
{
    //A static cast if the most common form.
    //Used to cast at compile time for explicit conversions
    std::cout << "Static Cast" << std::endl;
    int val = -1;
    double staticCastVal = static_cast<double>(val);
    std::cout << staticCastVal << "\n";
    std::cout << std::endl;

    //A dynamic cast is primarily used to convert a pointer/ref of a base class to a derived class
    std::cout << "Dynamic Cast" << std::endl;
    Foo* base = new Bar;
    Bar* d1 = dynamic_cast<Bar*>(base);
    if (d1 == nullptr)
	    std::cout << "null" << std::endl;
    else
        d1->Test();
    std::cout << std::endl;

    //A const cast converts the const status of a const member
    //Could cause undefined behaviour
    std::cout << "Const Cast" << std::endl;
    const int val2 = 10;
    const int* ptr = &val2;
    int* ptr2 = const_cast<int*>(ptr);
    std::cout << TimesTen(ptr2) << std::endl;
    std::cout << std::endl;

    //A reinterpret cast convert the type of a pointer
    std::cout << "Reinterpret Cast" << std::endl;
    int* p1 = new int(65);
    char* ch1 = reinterpret_cast<char*>(p1);
    std::cout << *p1 << std::endl;
    std::cout << *ch1 << std::endl;
    std::cout << p1 << std::endl;
    std::cout << ch1 << std::endl;
    std::cout << std::endl;
}