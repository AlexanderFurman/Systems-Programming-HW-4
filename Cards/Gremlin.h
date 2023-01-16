//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_GREMLIN_H
#define HW3_CLION_GREMLIN_H

#include "Battle.h"

class Gremlin : public Battle {

public:
    static const int FORCE = 5;
    static const int LOOT = 2;
    static const int PLAYER_HP_DAMAGE = 10;

    Gremlin();

    void applyMonsterEffect(Player *curPlayer) const override;

    ~Gremlin() override = default;
    Gremlin(const Gremlin&) = delete; ///???
    Gremlin& operator=(const Gremlin& other) = delete; ///???

};


#endif //HW3_CLION_GREMLIN_H
