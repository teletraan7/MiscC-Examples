#include <cstdio>
#include <iostream>
#include <string>
typedef std::string string;

class MyClass {
public:
    MyClass(int value) : data(value) {}

    void printData() const {
        std::cout << "Data: " << data << "\n";
    }

    void modifyData(int newValue) {
        data = newValue;
    }

private:
    int data;
};

//Example of const member method
class MemClass
{
public:
    void Func3 (string s) const
    {
        std::cout << "\nThis is Func3 in MemClass. If I tried to change MemS to '" + s + "' in this method it would not work. Const's use here keeps all member variables as read only.\n";
    }

private:
    string MemS{"This can't be altered by Func3"};
};

//Standard
void Func1 ()
{
   std::cout << "\nFunction 1 is just a standard method\n";
}

//Example of const input
void Func2 (const string s)
{
    std::cout << "\nFunction 2 is using a const input param, and therefore '" + s + "' is read only.\n";
}

//Example of const return type
string const Func4 ()
{
    std::cout << "\nFunction 4 is using a const return type. It would be best used when returning a const pointer, ref, or returning to a const variable.\n";
    return "This can't change";
}

void main()
{
    const string s = "The String";
    Func1();
    Func2(s);

    MemClass mem_class;
    mem_class.Func3(s);
    
    string * const ptrS = new string{"Const pointer to non const string"};
    std::cout << "\n" + *ptrS + "\n";
    //ptrS is a const pointer to a non const string, so the string CAN be changed. If you tried to change the pointer however it would not compile.
    *ptrS = "Const pointer to non const string that has been changed";
    std::cout << "\n" + *ptrS + "\n";

    //ptrW is a non const pointer to a const string, so the string can not be changed. However the pointer itself can be, as seen bellow.
    string const * ptrW = new string{"Non const Pointer to const string"};
    std::cout << "\n" + *ptrW + "\n";
    
    delete ptrW;
    printf("\nptrW was deleted.\n");

    //Since ptrW was non const pointer to a const string it can now be re pointed to different memory.
    ptrW = new string{"New non const Pointer to const string"};
    std::cout << "\n" + *ptrW + "\n";
    
    string k = "Non const string";
    string const * ptrK = &k;
    std::cout << "\n" + *ptrK + "\n";
    //This case is the same as above. K is not a const though so it can change. If you tried to change K by de-referencing ptrK it would not compile.
    k = "Non const string that was changed through the original value, not the pointer";
    std::cout << "\n" + *ptrK + "\n";

    string x = "B is a const pointer to a const string";
    //ptrB is a const pointer to a const string. It CAN'T be reassigned to point to a new address, OR edit the string via de-referencing.
    string const * const ptrB = &x;
    std::cout << "\n" + *ptrB + "\n";

    /*MyClass obj(42);
    const MyClass& constRef = obj;
    constRef.modifyData(10); This would not work as constRef is a reference to a const MyClass,
                                thus only const member can be called
    constRef.printData();*/
    
    string const str = Func4();
}