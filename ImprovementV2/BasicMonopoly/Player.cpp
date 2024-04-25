#include "Player.h"

#include <iostream>

#include "GoSpace.h"
#include "PropertySpace.h"

Player::Player(uint32_t initialCash, std::shared_ptr<BoardSpace> startSpace)
    : mWallet(initialCash), mCurrentSpace(startSpace)
{
}

//Getter for the current space the player is on
const std::shared_ptr<BoardSpace>& Player::GetCurrentSpace() const
{
    return mCurrentSpace;
}

bool Player::TakeCash(uint32_t cash)
{
    if (mWallet > cash)
    {
        mWallet -= cash;
        return true;
    }
    return false;
}

bool Player::BuyProperty()
{
    if (mCurrentSpace->GetmSpaceType() != ESpaceType::Property)
    {
        std::cout << "Not a property space\n";
        return false;
    }
    
    const std::shared_ptr<PropertySpace> currentPropSpace = std::dynamic_pointer_cast<PropertySpace>(mCurrentSpace);
    const uint32_t propRent = currentPropSpace->GetRent();
    if (!TakeCash(propRent))
    {
        std::cout << "Not enough money\n";
        return false;
    }
    
    mOwnedSpaces.push_back(mCurrentSpace);
    std::cout << "Property bought\n";
    return true;
}

void Player::MovePlayer(uint32_t spacesToMove)
{
    while (spacesToMove > 0)
    {
        mCurrentSpace = mCurrentSpace->pNext;
        if (mCurrentSpace->GetmSpaceType() == ESpaceType::Go)
        {
            const std::shared_ptr<GoSpace> goSpace = std::dynamic_pointer_cast<GoSpace>(mCurrentSpace);
            AddCash(goSpace->PassGo());
        }
        spacesToMove--;
    }
}

void Player::AddCash(uint32_t cash)
{
    mWallet += cash;
    std::cout << "Cash for the player: " << mWallet << "\n";
}