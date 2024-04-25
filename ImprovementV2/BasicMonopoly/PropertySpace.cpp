#include "PropertySpace.h"

#include <iostream>

PropertySpace::PropertySpace(std::shared_ptr<BoardSpace> previousSpace, uint32_t price, EPropertyColor color)
: BoardSpace(previousSpace, ESpaceType::Property), mPropertyDetails(new PropertyDetails(price, color))
{
}

ESpaceType PropertySpace::GetmSpaceType()
{
    return mSpaceType;
}

uint32_t PropertySpace::GetRent() const
{
    return mPropertyDetails->mRent;
}

void PropertySpace::BuyPropertyHouse()
{
    if (mPropertyDetails->BuyHouse())
    {
        std::cout << "House Bought \n";
    }
    else std::cout << "Can't buy house. \n";
}

void PropertySpace::BuyPropertyHotel()
{
    if (mPropertyDetails->BuyHotel())
    {
        std::cout << "Hotel Bought \n\n";
    }
    else std::cout << "Can't buy hotel. \n";
}