//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_MANA_H
#define HW3_CLION_MANA_H

#include "Card.h"

class Mana : public Card {

public:

    /**
     * Mana non-arguments constructor.
     */
    Mana();

    /**
     * healing 10 HP of current Player, only if current Player is of class Healer.
     * @param curPlayer - the current Player
     */
    void applyEncounter(const std::unique_ptr<Player>& curPlayer) const override;


    /************** DEFAULT/DELETED METHODS **************/

    ~Mana() override = default;
    Mana(const Mana&) = delete;
    Mana& operator=(const Mana& other) = delete;


    /************************ MEMBERS ************************/

    /** static members **/

private:

    static const int GAIN_HP = 10;


};


#endif //HW3_CLION_MANA_H
