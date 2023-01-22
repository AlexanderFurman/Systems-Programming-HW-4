//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_BARFIGHT_H
#define HW3_CLION_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {

public:

    /************************ METHODS ************************/

    /**
     * barFight non-arguments constructor.
     */
    Barfight();

    /**
     * taking 10 HP from current Player, unless current Player is of class Warrior.
     * @param curPlayer - the current Player
     */
    void applyEncounter(const std::unique_ptr<Player>& curPlayer) const override;

    /**************** DEFAULT/DELETED METHODS ****************/

    ~Barfight() override = default;
    Barfight(const Barfight&) = delete;
    Barfight& operator=(const Barfight& other) = delete;


    /************************ MEMBERS ************************/

    /** static members **/

private:

    static const int BARFIGHT_LOSE_HP = 10;
};


#endif //HW3_CLION_BARFIGHT_H
