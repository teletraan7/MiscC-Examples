#include "GoSpace.h"

GoSpace::GoSpace(std::shared_ptr<BoardSpace> previous, uint32_t award)
    : BoardSpace(previous, ESpaceType::Go), mAwardComponent(award)
{
}

GoSpace::~GoSpace()
{
}

uint32_t GoSpace::PassGo()
{
    return mAwardComponent.AwardMoney();
}

ESpaceType GoSpace::GetmSpaceType()
{
    return mSpaceType;
}
