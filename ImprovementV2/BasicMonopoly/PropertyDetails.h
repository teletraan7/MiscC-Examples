#pragma once
#include <cstdint>
#include <string>

enum EPropertyColor
{
    Brown = 0,
    Sky = 1,
    Pink = 2,
    Orange = 3,
    Red = 4,
    Yellow = 5,
    Green = 6,
    Blue = 7,
};

struct PropertyDetails
{
    PropertyDetails(uint32_t price, EPropertyColor color);
    bool BuyHouse();
    bool BuyHotel();
    uint32_t GetmBuildings();
    
    uint32_t mRent;
    //Use the bits as flags representing the house/hotels (0111 0001 Would be three houses and one hotel)
    //Saves space from having two 32 bit values
    //Plus it would be fun to try
    //Could be a char but I have it as a uint8_t for easier debugging
    uint8_t mBuildings;
    std::string mBuildingName;
    EPropertyColor mPropertyColor;
};