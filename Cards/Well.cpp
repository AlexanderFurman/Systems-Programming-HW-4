//
// Created by Omer Meushar on 16/01/2023.
//

#include "Well.h"
#include "Players/Ninja.h"


Well::Well(const std::string& name) : Card(name) {}

//omer 16.1: do we need to specifically address case of dead player?
void Well::applyEncounter(Player* curPlayer) const
{
    bool isNinja =  dynamic_cast<const Ninja*>(curPlayer)== nullptr;
    if(!isNinja) {
        curPlayer->damage(WELL_LOSE_HP);
    }
    printManaMessage(isNinja);
}