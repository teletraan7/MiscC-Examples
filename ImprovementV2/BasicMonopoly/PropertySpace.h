#pragma once
#include "BoardSpace.h"
#include "PropertyDetails.h"

class PropertySpace : public BoardSpace
{
public:
    PropertySpace(std::shared_ptr<BoardSpace> previousSpace, uint32_t price, EPropertyColor color);
    ESpaceType GetmSpaceType() override;
    uint32_t GetRent() const;
    void BuyPropertyHouse();
    void BuyPropertyHotel();
private:
    PropertyDetails* mPropertyDetails;
};
