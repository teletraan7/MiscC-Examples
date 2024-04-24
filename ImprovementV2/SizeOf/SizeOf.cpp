#include <iostream>
#include <vector>

void VoidFunction ()
{
    std::cout << "Size of VoidFunction:      0 bytes\n";
}

void LocalBool()
{
    bool newBool = true;
    std::cout << "Size of LocalBool:         " << sizeof(newBool) << " bytes\n";
}

void VectorPointer (const std::vector<int>* vec)
{
    std::cout << "Size of VectorPointer:     " << sizeof(vec) << " bytes\n";
}

void VectorRef (const std::vector<int>& vec)
{
    std::cout << "Size of VectorRef:         " << sizeof(vec) << " bytes\n";
}

void VectorVal (std::vector<int> vec)
{
    std::cout << "Size of VectorVal:         " << sizeof(vec) << " bytes\n";
}

bool ReturnBool()
{
    return false; //Returns an r-value so it doesn't take up memory
}

int main()
{
    //Size of primitive types
    std::cout << "Size of int:         " << sizeof(int) << " bytes\n";
    std::cout << "Size of float:       " << sizeof(float) << " bytes\n";
    std::cout << "Size of double:      " << sizeof(double) << " bytes\n";
    std::cout << "Size of char:        " << sizeof(char) << " byte\n";
    std::cout << "Size of short:       " << sizeof(short) << " bytes\n";
    std::cout << "Size of long:        " << sizeof(long) << " bytes\n";
    std::cout << "Size of long long:   " << sizeof(long long) << " bytes\n";
    std::cout << "Size of bool:        " << sizeof(bool) << " byte\n";
    std::cout << "Size of pointer:     " << sizeof(int*) << " byte\n";

    std::cout << "\n";
    
    //size of functions

    //THE RETURN TYPE OF A METHOD DOES NOT INCREASE THE MEMORY THE METHOD TAKES UP IN THE STACK
    //IT ONLY CHANGES HOW MUCH MEMORY THE WILL BE TAKEN UP WHERE IT IS CALLED/RETURNED

    VoidFunction();
    LocalBool();

    //These members will take up different spaces in the stack since they are passing the variable in different ways.
    const std::vector<int> vec {1, 2, 3, 4, 5, 6};
    VectorPointer(&vec);
    VectorRef(vec);
    VectorVal(vec);
    
    //temp take up memory as ReturnBool returns a value, however as mentioned above that DOESN'T increase the stack size of ReturnBool
    bool temp = ReturnBool();
    
    return 0;
}
