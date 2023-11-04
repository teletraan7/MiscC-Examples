#include <cstdio>
#include <iostream>

#pragma region Example of Constructor/Destructor Order of Operations
class Base
{
public:
    Base()
    {
        //this->foo();
        printf("\nBase constructor \n");
    }

    ~Base()
    {
        printf("Base destructor \n");
    }

    /*virtual void foo()
    {
        printf("Base::foo() \n");
    }*/
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        printf("Derived1 constructor \n");
    }

    ~Derived1()
    {
        printf("Derived1 destructor \n");
    }

    /*void foo() override
    {
        // This is not called because derived doesn't fully exist yet, causing the base to be called.
        printf("Derived::foo() \n");
    }*/
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        printf("Derived2 constructor \n");
    }

    ~Derived2()
    {
        printf("Derived2 destructor \n\n");
    }
};
# pragma endregion

#pragma region Example of Virtual Destructor
class Shape
{
public:
    virtual ~Shape()
    {
        printf("Shape destructor \n");
    }

    virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(int i) : data(new int{i})
    {
    }
    
    ~Rectangle() override
    {
        delete data;
        printf("Rectangle Destructor \n");
    }

    void draw() override
    {
        printf("\nDraw a Rectangle \n");
    }
private:
    int* data;
};
#pragma endregion

void main()
{
    Derived1 d1;
    Derived2 d2;
    Shape* ptrShape = new Rectangle(2);
    
    ptrShape->draw();
    //If the destructor of Shape was not virtual the destructor of Rectangle would not be called. Thus the memory stored in Rectangle.data would be inaccessible/leaked
    delete ptrShape;
    
    printf("\nPress Enter to exit. \n");
    std::cin.get();

    printf("Other Destructors will now be fired");
}