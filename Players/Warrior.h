//
// Created by alex on 1/15/23.
//

#ifndef HW3_CLION_WARRIOR_H
#define HW3_CLION_WARRIOR_H

#include "Player.h"

class Warrior : public Player
{
public:
    explicit Warrior(const std::string& name); //: Player(name){}

    int getAttackStrength() const override;
//    {
//        return DOUBLE*m_force+m_level;
//    }

    std::string getJob() const override;
    ~Warrior() override = default;

//    {
//        return "Warrior";
//    }
};

#endif //HW3_CLION_WARRIOR_H
