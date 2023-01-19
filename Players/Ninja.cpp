//
// Created by alex on 1/19/23.
//

#include "Ninja.h"

Ninja::Ninja(const std::string& name): Player(name) {}

void Ninja::addCoins(int addedCoins)
{
    m_coins += DOUBLE*addedCoins;
}

std::string Ninja::getJob() const
{
    return "Ninja";
}
