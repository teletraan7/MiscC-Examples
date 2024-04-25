#include "BoardSpace.h"

BoardSpace::BoardSpace(std::shared_ptr<BoardSpace> previousSpace, ESpaceType type) : pPrev(previousSpace), pNext(nullptr), mSpaceType(type)
{
}

BoardSpace::~BoardSpace()
= default;