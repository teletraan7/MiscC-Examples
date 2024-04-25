#pragma once
#include <memory>

enum ESpaceType
{
    Blank = 0,
    Go = 1,
    Parking = 2,
    Jail = 3,
    Property = 4,
    Utility = 5,
    Rail = 6
};

class BoardSpace
{
public:
    BoardSpace(std::shared_ptr<BoardSpace> previousSpace, ESpaceType type);
    
    virtual ~BoardSpace();
    
    virtual ESpaceType GetmSpaceType() = 0;
    //Add proper methods for adding an item to the list, and removing and item from it.
    std::shared_ptr<BoardSpace> pPrev;
    std::shared_ptr<BoardSpace> pNext;
protected:
    ESpaceType mSpaceType;
};