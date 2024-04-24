#include <iostream>

class Base
{
public:
    virtual void VirtualPrintData()
    {
        std::cout << "Base Method: ";
        std::cout << GetData() << "\n";
    }

    void NonVPrintData()
    {
        std::cout << "Base Method: ";
        std::cout << GetData() << "\n";
    }

    void PrintDataVirtualFromNon()
    {
        std::cout << "Base Method: ";
        std::cout << VirtualGetData() << "\n";
    }

    int GetData()
    {
        std::cout << " Base Data: ";
        return 420;
    }

    virtual int VirtualGetData()
    {
        std::cout << " Base Data: ";
        return 867;
    }
};

class Derived : public Base
{
public:
    void VirtualPrintData() override
    {
        //This will print the GetData in this class. Even though it's not a virtual, the print data method is.
        //So when entering the override of PrintData we then use the GetData in this scope/object rather than the base
        std::cout << "Derived Method: ";
        std::cout << GetData() << "\n";
    }

    void NonVPrintData()
    {
        std::cout << "Derived Method: ";
        std::cout << GetData() << "\n";
    }

    int GetData()
    {
        std::cout << " Derived Data: ";
        return 69;
    }

    int VirtualGetData() override
    {
        std::cout << " Derived Data: ";
        return 5309;
    }
};

int main()
{
    Base* pBase = new Base();
    std::cout << "\n Base* to Base Object \n";
    //Will call Base::VirtualPrintData as PrintData
    pBase->VirtualPrintData();

    //Will call Base::NonVPrintData
    pBase->NonVPrintData();

    //Will call Base::PrintDataVirtualFromNon, which will call Base::VirtualGetData
    pBase->PrintDataVirtualFromNon();
    
    Base* pBaseDerived = new Derived();
    std::cout << "\n Base* to Derived Object \n";
    //Will call Derived::VirtualPrintData as PrintData is virtual
    pBaseDerived->VirtualPrintData();

    //Will call Base::NonVPrintData
    pBaseDerived->NonVPrintData();

    //Will call Base::PrintDataVirtualFromNon, BUT that will call Derived:VirtualGetData as pBase is a pointer to a derived object
    pBaseDerived->PrintDataVirtualFromNon();
    
    //Can't be done without explicit casting
    //Derived* pDerived = new Base();

    Derived* pDerived = new Derived();
    std::cout << "\n Derived* to Derived Object \n";
    //Will call Derived::VirtualPrintData as pDerived is a Derived object
    pDerived->VirtualPrintData();

    //Will call Derived::NonVPrintData as pDerived is a Derived object
    pDerived->NonVPrintData();

    //Will call Base::PrintDataVirtualFromNon, BUT that will call Derived:VirtualGetData as pBase is a pointer to a derived object
    pDerived->PrintDataVirtualFromNon();
    return 0;
}