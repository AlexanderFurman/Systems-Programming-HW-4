//
// Created by Omer Meushar on 16/01/2023.
//

#include "Mana.h"
#include "Players/Healer.h"


Mana::Mana(const std::string& name) : Card(name) {}

void Mana::applyEncounter(Player* curPlayer) const
{
    bool isHealer =  dynamic_cast<const Healer*>(curPlayer)== nullptr;
    if(isHealer) {
        curPlayer->heal(GAIN_HP);
    }
    printManaMessage(isHealer);
}
