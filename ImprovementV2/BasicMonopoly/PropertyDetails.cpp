#include "PropertyDetails.h"

PropertyDetails::PropertyDetails(uint32_t const price, EPropertyColor const color)
    : mRent(price), mBuildings(0), mPropertyColor(color)
{
}

bool PropertyDetails::BuyHouse()
{
    bool houseBought = false;
    for(int i = 4; i < 8; i++)
    {
        if (!(mBuildings & 1 << i))
        {
            const uint8_t mask = 1 << i;
            mBuildings = mBuildings | mask;
            houseBought = true;
            break;
        }
    }
    return houseBought;
}

bool PropertyDetails::BuyHotel()
{
    //Shift the bits representing the houses over into the first byte of mBuildings
    //This allows us to focus on the houses and ignore any hotels
    uint8_t houseMask = mBuildings >> 4;
    //Using 0x0F as a mask to check for four houses as 0x0F = 1111
    if (houseMask != 0x0F) 
    {
        return false;
    }
    
    bool hotelBought = false;
    for(int i = 0; i < 4; i++)
    {
        if (!(mBuildings & 1 << i))
        {
            const uint8_t mask = 1 << i;
            mBuildings = (mBuildings & 0x0F) | mask;
            hotelBought = true;
            break;
        }
    }
    return hotelBought;
}

uint32_t PropertyDetails::GetmBuildings()
{
    return mBuildings;
}
