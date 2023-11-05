#include <iostream>
#include <string>

class MoveClass
{
public:
    MoveClass(const int i, const int x) : data1(i), data2(new int{x})
    {
        std::cout << "The base constructor with the input of: " + std::to_string(i) + " and: " + std::to_string(x) + "\n";
    }

    //Move constructor - Basically a shallow copy that then sets the pointers from "other" to nullptr.
    MoveClass(MoveClass&& other) noexcept : data1(other.data1), data2(other.data2)
    {
        other.data2 = nullptr;
        std::cout << "The move constructor has now taken control of the pointer and left the old object with data2: " << other.data2 << std::endl;
    }

    /*//Copy constructor (This is shallow since only the pointers value is being copied, but not the value of whats being pointed to.)
    MoveClass(const MoveClass& other) : data1{other.data1}, data2{other.data2}
    {
        std::cout << "Shallow Copy\n";
    }*/

    //Copy constructor (This is deep since a copy of the int data2 points to is made, rather than just copying the address that data2 stores)
    MoveClass(const MoveClass& other) : data1(other.data1), data2(new int{*other.data2})
    {
        std::cout << "Deep Copy has duplicated the value pointed to by data2, creating a new pointer.\n";
    }

    void PrintData();

private:
    int data1;
    int* data2;
};

//Just demonstrating how a member function can be defined outside of the class structure
void MoveClass::PrintData()
{
    std::cout << "Data1: " << data1 << " - Data2: " << data2 << " - Data2 Value: " << *data2 << std::endl;
}

int main ()
{
    MoveClass mc(420, 69);
    mc.PrintData();
    MoveClass mc2(std::move(mc));
    mc2.PrintData();
    MoveClass mc3(mc2);
    mc3.PrintData();
    //mc.PrintData(); //Will error out since mc.data2 is a null ptr.
    
    std::cout << "\nPress Enter to exit....\n";
    std::cin.get();
    return 0;
}
