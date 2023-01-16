//
// Created by Omer Meushar on 16/01/2023.
//

#include "Dragon.h"
#include "Players/Player.h"

void Dragon::applyMonsterEffect(Player *curPlayer) const
{
    curPlayer->damage(curPlayer->getHP());
}

Dragon::Dragon() : Battle("Dragon", FORCE, LOOT, 0) {}

