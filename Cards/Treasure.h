//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_TREASURE_H
#define HW3_CLION_TREASURE_H

#include "Card.h"

class Treasure : public Card
{
public:

    /**
     * Treasure non-arguments constructor.
     */
    Treasure();

    /**
     * awards current Player with 10 coins.
     * @param curPlayer - the current Player
     */
    void applyEncounter(const std::unique_ptr<Player>& curPlayer) const override;

    /**************** DEFAULT/DELETED METHODS ****************/

    ~Treasure() override = default;
    Treasure(const Treasure&) = delete;
    Treasure& operator=(const Treasure& other) = delete;

    /************************ MEMBERS ************************/

private:

    /** static members **/
    static const int TREASURE_COINS = 10;

};

#endif //HW3_CLION_TREASURE_H
