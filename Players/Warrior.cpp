//
// Created by alex on 1/19/23.
//

#include "Warrior.h"

Warrior::Warrior(const std::string& name): Player(name){}

int Warrior::getAttackStrength() const
{
    return DOUBLE*m_force+m_level;
}

std::string Warrior::getJob() const
{
    return "Warrior";
}