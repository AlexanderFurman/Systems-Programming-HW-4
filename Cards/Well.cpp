//
// Created by Omer Meushar on 16/01/2023.
//

#include "Well.h"
#include "../Players/Ninja.h"


Well::Well() : Card("Well") {}

void Well::applyEncounter(const std::unique_ptr<Player>& curPlayer) const
{
    bool isNinja =  dynamic_cast<const Ninja*>(curPlayer.get()) != nullptr;
    if(!isNinja) {
        curPlayer->damage(WELL_LOSE_HP);
    }
    printWellMessage(isNinja);
}