//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_WITCH_H
#define HW3_CLION_WITCH_H

#include "Battle.h"

class Witch : public Battle {

public:

    /**
     * Witch non-arguments constructor.
     */
    Witch();

    /**
     * applies special Battle effects of Witch on the current player, making the player lose 1 force point.
     * @param curPlayer - the current player.
     */
    void applyMonsterEffect(const std::unique_ptr<Player>& curPlayer) const override;


    /************** DEFAULT/DELETED METHODS **************/

    ~Witch() override = default;
    Witch(const Witch&) = delete;
    Witch& operator=(const Witch& other) = delete;

    /************************ MEMBERS ************************/

    /** static members **/
private:

    static const int FORCE = 11;
    static const int LOOT = 2;
    static const int PLAYER_HP_DAMAGE = 10;
};

#endif //HW3_CLION_WITCH_H
