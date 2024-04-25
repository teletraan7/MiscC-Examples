#pragma once
#include <cstdint>

//In monopoly, you can be awarded money via GO, Free Parking, and chance cards(?).
//So this component could be reused for them all.
class AwardComponent
{
public:
    AwardComponent(uint32_t award);
    
    uint32_t AwardMoney() const;
private:
    const uint32_t mAwardValue;
};
