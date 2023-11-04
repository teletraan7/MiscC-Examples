#pragma once
#include <memory>

class UniquePtrMoveConstructor
{
public:
    UniquePtrMoveConstructor(const int& i);
    
    UniquePtrMoveConstructor(UniquePtrMoveConstructor&& other) noexcept;

private:
    std::unique_ptr<int32_t> data;
};
