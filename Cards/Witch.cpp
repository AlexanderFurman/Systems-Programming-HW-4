//
// Created by Omer Meushar on 16/01/2023.
//

#include "Witch.h"
//#include "Players/Player.h"

void Witch::applyMonsterEffect(const std::unique_ptr<Player>& curPlayer) const
{
    curPlayer->decForce();
}

Witch::Witch() : Battle("Witch", FORCE, LOOT, PLAYER_HP_DAMAGE) {}

