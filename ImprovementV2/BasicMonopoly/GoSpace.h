#pragma once
#include <cstdint>

#include "AwardComponent.h"
#include "BoardSpace.h"

class GoSpace : public BoardSpace
{
public:
    GoSpace(std::shared_ptr<BoardSpace> previous, uint32_t award);
    ~GoSpace() override;
    uint32_t PassGo();
    ESpaceType GetmSpaceType() override;
private:
    //When this was a pointer it would mess up and change the value of mAwardValue when the factory was making it
    //Think it has something to do with using shared pointer. Look into it more.
    AwardComponent mAwardComponent;
};
