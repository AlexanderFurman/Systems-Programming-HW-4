//
// Created by Omer Meushar on 16/01/2023.
//

#include "Dragon.h"

void Dragon::applyMonsterEffect(const std::unique_ptr<Player>& curPlayer) const
{
    curPlayer->damage(curPlayer->getHP());
}

Dragon::Dragon() : Battle("Dragon", FORCE, LOOT, PLAYER_HP_DAMAGE) {}

