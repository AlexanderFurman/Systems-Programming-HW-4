//
// Created by Omer Meushar on 16/01/2023.
//

#include "Mana.h"
#include "Players/Healer.h"


Mana::Mana() : Card("Mana") {}

void Mana::applyEncounter(const std::unique_ptr<Player>& curPlayer) const
{
    bool isHealer =  dynamic_cast<const Healer*>(curPlayer.get()) == nullptr;
    if(isHealer) {
        curPlayer->heal(GAIN_HP);
    }
    printManaMessage(isHealer);
}
