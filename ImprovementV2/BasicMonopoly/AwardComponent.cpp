#include "AwardComponent.h"

AwardComponent::AwardComponent(const uint32_t award)
    : mAwardValue(award)
{
}

uint32_t AwardComponent::AwardMoney() const
{
    return mAwardValue;
}