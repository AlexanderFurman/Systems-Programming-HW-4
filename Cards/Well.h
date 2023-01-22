//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_WELL_H
#define HW3_CLION_WELL_H

#include "Card.h"

class Well : public Card{

public:

    /************************ METHODS ************************/

    /**
     * Well non-arguments constructor.
     */
    Well();

    /**
     * taking 10 HP from current Player, unless current Player is of class Ninja.
     * @param curPlayer - the current Player
     */
    void applyEncounter(const std::unique_ptr<Player>& curPlayer) const override;


    /**************** DEFAULT/DELETED METHODS ****************/

    ~Well() override = default;
    Well(const Well&) = delete;
    Well& operator=(const Well& other) = delete;

    /************************ MEMBERS ************************/

    /** static members **/

private:

    static const int WELL_LOSE_HP = 10;

};


#endif //HW3_CLION_WELL_H
