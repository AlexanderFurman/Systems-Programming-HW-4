//
// Created by Omer Meushar on 16/01/2023.
//

#include "Card.h"
#include "Merchant.h"

/*** static functions: ***/
static bool checkSufficientMoney(const Player* player, int cost);
static int validateMerchantUserInput();


/*** Merchant functions: ***/
Merchant::Merchant(const std::string& name) : Card(name){}

//omer 16/1: how do we make sure if he has enough coins? specific func? exception?
void Merchant::applyEncounter(Player* curPlayer) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,curPlayer->getName(),curPlayer->getCoins());
    int userNum = validateMerchantUserInput();
    if(userNum == ACTION_DO_NOTHING) {
        printMerchantSummary(std::cout,curPlayer->getName(),userNum,0);
        return;
    }
    //else - buying HP or Force:
    int cost = (userNum==ACTION_BUY_HP_POTION ? COST_HP : COST_FORCE_BOOST);
    if(checkSufficientMoney(curPlayer,cost)) { // player has enough coins
        curPlayer->pay(cost);
        printMerchantSummary(std::cout,curPlayer->getName(),userNum,cost);
    }
    else { //not sufficient coins
        printMerchantInsufficientCoins(std::cout);
    }
}

static bool checkSufficientMoney(const Player* player, int cost)
{
    int playerCoins = player->getCoins();
    assert(playerCoins>=0 && cost>0);
    return playerCoins>=cost;
}

static int validateMerchantUserInput()
{
    char userInput[Merchant::USER_INPUT_SIZE];
    int userNum;
    while (true)
    {
        std::cin.getline(userInput,sizeof(userInput));
        userNum = std::stoi(userInput);
        if(userNum < Merchant::ACTION_DO_NOTHING || userNum > Merchant::ACTION_BUY_FORCE_BOOST)
        {
            printInvalidInput();
            continue;
        }
        return userNum;
    }
}

//validateMerchantUserInput alternative with try and catch:
/*
static int validateMerchantUserInput()
{
    bool validInputFlag = false;
    char userInput[Merchant::USER_INPUT_SIZE];
    int userNum = -1;
    while (validInputFlag == false)
    {
        try{
            std::cin.getline(userInput,sizeof(userInput));
            userNum = std::stoi(userInput);
            if(userNum<Merchant::ACTION_DO_NOTHING || userNum>Merchant::ACTION_BUY_FORCE_BOOST)
            {
                throw InvalidMerchantInput();
            }
        }
        catch(...)
        {
            printInvalidInput();
            continue;
        }
        validInputFlag= true;
    }
}
 * */
