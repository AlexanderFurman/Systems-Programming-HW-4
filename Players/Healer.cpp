//
// Created by alex on 1/19/23.
//

#include "Healer.h"


Healer::Healer(const std::string& name): Player(name){}

void Healer::heal(int addedHP)
{
    m_HP = (m_HP+ DOUBLE*addedHP>=m_maxHP) ? m_maxHP : m_HP+ DOUBLE*addedHP;
}

std::string Healer::getJob() const
{
    return "Healer";
}
