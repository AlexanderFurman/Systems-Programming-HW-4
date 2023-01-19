//
// Created by alex on 1/14/23.
//

#ifndef HW3_CLION_NINJA_H
#define HW3_CLION_NINJA_H

#include "Player.h"

class Ninja : public Player
{
public:
    explicit Ninja(const std::string& name); //: Player(name) {}

    void addCoins(int addedCoins) override;
//    {
//        m_coins += DOUBLE*addedCoins;
////        m_coins += (addedCoins<=0) ? 0 : 2*addedCoins;
//    }

    std::string getJob() const override;
//    {
//        return "Ninja";
//    }

};

#endif //HW3_CLION_NINJA_H
