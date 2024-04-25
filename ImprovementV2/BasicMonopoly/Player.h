#pragma once
#include <cstdint>
#include <vector>
#include "BoardSpace.h"

class Player
{
public:
    Player(uint32_t initialCash, std::shared_ptr<BoardSpace> startSpace);
    bool BuyProperty();
    bool TakeCash(uint32_t cash);
    const std::shared_ptr<BoardSpace>& GetCurrentSpace() const;
    void MovePlayer(uint32_t spacesToMove);
    void AddCash(uint32_t cash);
    
private:
    uint32_t mWallet;
    std::shared_ptr<BoardSpace> mCurrentSpace;
    std::vector<std::shared_ptr<BoardSpace>> mOwnedSpaces;
};
