#include <iostream>
#include <vector>

#include "BoardFactory.h"
#include "BoardSpace.h"
#include "Player.h"
#include "PropertyDetails.h"
#include "PropertySpace.h"

/*
 * -Jonathon Neal-
 * This project is a sim/demo of Monopoly I'm slowly building piece by piece
 * Rather than make this into a fully functional game I will hard code specific steps and interactions to simulate gameplay
 * The purpose is to demonstrate some OOP design and C++ fundamentals without getting bogged down by making UI, AI, and everything
 * else that would come with a fully functional game.
 */

int main()
{
    //The board
    BoardData BD[] =
    {
        {ESpaceType::Go, 200},
        {ESpaceType::Property, 25, EPropertyColor::Brown},
        {ESpaceType::Property, 50, EPropertyColor::Brown},
        {ESpaceType::Property, 100, EPropertyColor::Sky},
        {ESpaceType::Property, 150, EPropertyColor::Sky},
        {ESpaceType::Property, 225, EPropertyColor::Pink},
        {ESpaceType::Property, 300, EPropertyColor::Pink},
        {ESpaceType::Property, 400, EPropertyColor::Orange},
        {ESpaceType::Property, 600, EPropertyColor::Red},
        {ESpaceType::Property, 900, EPropertyColor::Yellow},
        {ESpaceType::Property, 1300, EPropertyColor::Green},
        {ESpaceType::Property, 1800, EPropertyColor::Blue}
    };

    //Might be worth making this a map for direct lookup of spaces. Not needed ATM though.
    std::vector<BoardData> mBoardData;
    mBoardData.reserve(12);
    
    for (int i = 0; i < sizeof(BD) / sizeof(BD[0]); i++)
    {
        mBoardData.push_back(BD[i]);
    }
    
    //Linked list of board spaces starting from GO
    const std::shared_ptr<BoardSpace> mBoardSpace = BoardFactory::CreateSpace(mBoardData);

    Player* playerOne = new Player(1000, mBoardSpace);
    //uint32_t roll = rand() % 6 + 1;
    
    playerOne->MovePlayer(3);
    playerOne->BuyProperty();
    playerOne->MovePlayer(8);
    playerOne->BuyProperty();
    playerOne->MovePlayer(9);
    
    /*//This section is testing the house/hotel buying. It should finish with four houses and four hotels, a uint8 value of 255.
    //The last two calls should fail to buy both a house and hotel
    std::shared_ptr<PropertySpace> propSpace = std::dynamic_pointer_cast<PropertySpace>(mBoardSpace->pNext);
    for (int i = 0; i <= 20; i++)
    {
        if (i % 4 == 0 && i > 0)
        {
            propSpace->BuyPropertyHotel();
        }
        propSpace->BuyPropertyHouse();
    }*/

    return 0;
}
