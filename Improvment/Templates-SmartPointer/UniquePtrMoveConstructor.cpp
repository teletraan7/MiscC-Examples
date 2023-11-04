#include "UniquePtrMoveConstructor.h"
#include <iostream>
UniquePtrMoveConstructor::UniquePtrMoveConstructor(const int& i) : data(std::make_unique<int>(i))
{
}

UniquePtrMoveConstructor::UniquePtrMoveConstructor(UniquePtrMoveConstructor&& other) noexcept : data(std::move(other.data))
{
    std::cout << "Move Constructor" << std::endl;
    std::cout << "Other data has been nulled via the unique pointer. No need to do so manually. " << other.data << std::endl;
}
