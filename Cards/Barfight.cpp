//
// Created by Omer Meushar on 16/01/2023.
//

#include "Barfight.h"
#include "Players/Warrior.h"


Barfight::Barfight(const std::string& name) : Card(name) {}

//omer 16.1: do we need to specifically address case of dead player?
void Barfight::applyEncounter(Player* curPlayer) const
{
    bool isWarrior =  dynamic_cast<const Warrior*>(curPlayer)== nullptr;
    if(!isWarrior) {
        curPlayer->damage(BARFIGHT_LOSE_HP);
    }
    printManaMessage(isWarrior);
}