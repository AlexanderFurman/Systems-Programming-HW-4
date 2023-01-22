//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_GREMLIN_H
#define HW3_CLION_GREMLIN_H

#include "Battle.h"

class Gremlin : public Battle {

public:

    /************************ METHODS ************************/

    /**
     * Gremlin non-arguments constructor.
     */
    Gremlin();

    /**
     * applies special Battle effects of Gremlin on the current player, making no change besides loss of HP.
     * @param curPlayer - the current player.
     */
    void applyMonsterEffect(const std::unique_ptr<Player>& curPlayer) const override;

    /************** DEFAULT/DELETED METHODS **************/

    ~Gremlin() override = default;
    Gremlin(const Gremlin&) = delete; ///???
    Gremlin& operator=(const Gremlin& other) = delete; ///???

    /************************ MEMBERS ************************/

private:

    /** static members of class **/

    static const int FORCE = 5;
    static const int LOOT = 2;
    static const int PLAYER_HP_DAMAGE = 10;
};


#endif //HW3_CLION_GREMLIN_H
