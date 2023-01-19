//
// Created by Omer Meushar on 16/01/2023.
//

#include "Barfight.h"
#include "Players/Warrior.h"


Barfight::Barfight() : Card("Barfight") {}

//omer 16.1: do we need to specifically address case of dead player?
void Barfight::applyEncounter(const std::unique_ptr<Player>& curPlayer) const
{
    bool isWarrior =  dynamic_cast<const Warrior*>(curPlayer.get())== nullptr;
    if(!isWarrior) {
        curPlayer->damage(BARFIGHT_LOSE_HP);
    }
    printBarfightMessage(isWarrior);
}

std::ostream& Card::virtualPrintCard(std::ostream& os) const
{
    printCardDetails(os,m_name);
}