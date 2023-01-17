//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_WITCH_H
#define HW3_CLION_WITCH_H

#include "Battle.h"

class Witch : public Battle {

public:
    static const int FORCE = 11;
    static const int LOOT = 2;
    static const int PLAYER_HP_DAMAGE = 10;

    Witch();

    void applyMonsterEffect(Player *curPlayer) const override;

    ~Witch() override = default;
    Witch(const Witch&) = delete; ///???
    Witch& operator=(const Witch& other) = delete; ///???

};

#endif //HW3_CLION_WITCH_H
