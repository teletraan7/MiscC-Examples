#pragma once
#include <vector>

#include "BoardSpace.h"
#include "PropertyDetails.h"

struct BoardData
{
    ESpaceType type;
    uint32_t money;
    EPropertyColor color;
};

class BoardFactory
{
public:
    static std::shared_ptr<BoardSpace> CreateSpace(const std::vector<BoardData>& spaceData);
};
