#include <iostream>
#include <string>
#include <memory>
#include "Swapper.h"
typedef std::string String;

//This class will take an two types T and compare them to each other, returning the largest. This only works if the type T is a type supporting the comparison > operator.
//Templates must be declared and defined in the same file.
template <typename  T>
T GetBigger(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    //Standard unique pointer. As a smart pointer you no longer need to manually delete the pointer when no longer used.
    //As a unique pointer only one pointer can "own" this memory address.
    std::unique_ptr<double_t> myDubPtr = std::make_unique<double_t>(); //You would pass the constructor paramater in the () if the pointer pointed to a class.
    *myDubPtr = 3.14;
    std::cout << "Pointer value: " << *myDubPtr << std::endl;

    //Pointer to array
    std::unique_ptr<int32_t[]> arrPtr = std::make_unique<int32_t[]>(5);
    for (int i = 0; i < 5; i++)
    {
        arrPtr[i] = i * 2;
        std::cout << "Pointer value: " << arrPtr[i] << std::endl;
    }

    //Change ownership
    std::unique_ptr<double_t> otherPtr = std::move(myDubPtr);
    std::cout << "Other Pointer value: " << *otherPtr << std::endl;
    myDubPtr = std::make_unique<double_t>(6.28);
    std::cout << "New myDub Pointer value: " << *myDubPtr << std::endl;

    //Class unique pointer
    std::unique_ptr<Swapper<int32_t>> ptrSwapper = std::make_unique<Swapper<int32_t>>(420, 69);
    std::cout << "Swapper Pointer value 1: " << ptrSwapper->getFirst() << std::endl;
    std::cout << "Swapper Pointer value 2: " << ptrSwapper->getSecond() << std::endl;
    ptrSwapper->swap();
    std::cout << "Swapper Pointer value 1 after: " << ptrSwapper->getFirst() << std::endl;
    std::cout << "Swapper Pointer value 2 after: " << ptrSwapper->getSecond() << std::endl;
    
    String name1 = "John";
    String name2 = "Neal";
    
    Swapper<std::int32_t> intSwapper(5,10);
    Swapper<String> stringSwapper(name1,name2);

    std::double_t biggerDub = GetBigger(3.14, 5.55);
    std::int32_t biggerInt = GetBigger(11,9);
    String biggerString = GetBigger(name1, name2);

    std::cout << "Bigger items: " << std::endl;
    std::cout << "\t" << biggerDub << std::endl;
    std::cout << "\t" << biggerInt << std::endl;
    std::cout << "\t" << biggerString << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Testing the swapper." << std::endl;
    std::cout << intSwapper.getFirst() << " " << intSwapper.getSecond() << std::endl;
    std::cout << stringSwapper.getFirst() << " " << stringSwapper.getSecond() << std::endl;
    std::cout << std::endl << std::endl;

    intSwapper.swap();
    stringSwapper.swap();

    std::cout << "After the swap." << std::endl;
    std::cout << intSwapper.getFirst() << " " << intSwapper.getSecond() << std::endl;
    std::cout << stringSwapper.getFirst() << " " << stringSwapper.getSecond() << std::endl;
    std::cout << std::endl << std::endl;
    return 0;
}