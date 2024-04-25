#include "BoardFactory.h"

#include "GoSpace.h"
#include "PropertySpace.h"

//Takes in the board data and creates a linked list of various board space derivatives.
std::shared_ptr<BoardSpace> BoardFactory::CreateSpace(const std::vector<BoardData>& spaceData)
{
    std::shared_ptr<BoardSpace> firstSpace;
    std::shared_ptr<BoardSpace> currentSpace;
    
    for (const BoardData space : spaceData)
    {
        std::shared_ptr<BoardSpace> newSpace;
        switch (space.type)
        {
        case ESpaceType::Go:
            { //Learned about using brackets INSIDE a case to prevent a scope error.
                //Create GO space
                GoSpace testSpace(currentSpace, space.money);
                newSpace = std::make_shared<GoSpace>(testSpace);
                firstSpace = newSpace;
                currentSpace = newSpace;
                break;
            }
        case ESpaceType::Property:
            {
                //Create Proptery space
                newSpace = std::make_shared<PropertySpace>(PropertySpace(currentSpace, space.money, space.color));
                currentSpace->pNext = newSpace;
                currentSpace = newSpace;
                break;
            }
        }
    }

    currentSpace->pNext = firstSpace;

    return firstSpace;
}