//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_DRAGON_H
#define HW3_CLION_DRAGON_H

#include "Battle.h"

class Dragon : public Battle {

public:

    /**
     * Dragon non-arguments constructor.
     */
    Dragon();

    /**
     * applies special Battle effects of Dragon on the current player, making the player lose all his HP.
     * @param curPlayer - the current player.
     */
    void applyMonsterEffect(const std::unique_ptr<Player>& curPlayer) const override;

    /************** DEFAULT/DELETED METHODS **************/

    ~Dragon() override = default;
    Dragon(const Dragon&) = delete; ///???
    Dragon& operator=(const Dragon& other) = delete; ///???


    /************************ MEMBERS ************************/

private:

    /** static members **/

    static const int FORCE = 25;
    static const int LOOT = 1000;
    static const int PLAYER_HP_DAMAGE = 1;

};


#endif //HW3_CLION_DRAGON_H
