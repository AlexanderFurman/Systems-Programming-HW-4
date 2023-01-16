//
// Created by Omer Meushar on 16/01/2023.
//

#include "Treasure.h"

Treasure::Treasure(const std::string& name) : Card(name) {}

void Treasure::applyEncounter(Player* curPlayer) const
{
    curPlayer->addCoins(TREASURE_COINS);
    printTreasureMessage();
}
