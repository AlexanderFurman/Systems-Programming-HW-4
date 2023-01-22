//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_BATTLE_H
#define HW3_CLION_BATTLE_H

#include "Card.h"

class Battle : public Card {
public:
    /************************ METHODS ************************/

    /**
     * applies battle between the Monster class inheriting this function and the current player.
     * @param curPlayer - the current player.
     */
    void applyEncounter(const std::unique_ptr<Player>& curPlayer) const override;

    /**
     * applies special Battle effects of a Monster class inheriting this function on the current player.
     * @param curPlayer - the current player.
     */
    virtual void applyMonsterEffect(const std::unique_ptr<Player>& curPlayer) const = 0;

    /**
     * override function printing monster card details, specific to the Monster class inheriting this function.
     * @param os - std::ostream type stream written to by the function.
     */
    void virtualPrintAddedDetails(std::ostream& os) const override;


    /************** DEFAULT/DELETED METHODS **************/

    ~Battle() override = default;
    Battle(const Battle&) = delete;
    Battle& operator=(const Battle& other) = delete;

protected:
    /**
     * constructor of battle, creating the battle card (abstract class - specific moster class inherits it)
     * @param name - name of the Battle Card
     * @param force - force of the Battle Card
     * @param loot - number of coins the user gets if wins the monster.
     * @param playerHPDamage - damage dealt to the player upon loss in battle.
     */
    Battle(const std::string& name, int force, int loot, int playerHPDamage);


    /************************ MEMBERS ************************/

private:
    int m_force;
    int m_loot;
    int m_playerHPDamage;

};



#endif //HW3_CLION_BATTLE_H
