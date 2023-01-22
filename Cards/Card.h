//
// Created by Omer Meushar on 20/01/2023.
//
#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include <memory>
#include "../Players/Player.h"
#include "../utilities.h"
#include "../Exception.h"

//*
// *  CardType:
// *  Each card has a type:
// *  Gremlin, Witch, Dragon - Battle against a monster.
// *  Merchant - Increase current player's force/HP for money.
// *  Treasure - current player gets 10 coins.
// *  Well - current player loses 10 HP unless he's a Ninja.
// *  Barfight - current player loses 10 HP unless he's a Warrior.
// *  Mana - if current player is a Healer, Increase HP by 10 points - which means 20 for Healer (no more than maxHP points).
// */

class Card {
public:

    /************ METHODS ************/

    /**
     * Handling the player's applyEncounter with the card:
     *
     * @param curPlayer - The current player.
     * @return
     *      void
    */
    virtual void applyEncounter(const std::unique_ptr<Player>& curPlayer) const = 0; ///omer 16.1: const method?


    /**
     * adds added details of a class inheriting Card.
     * @param os - std::ostream type stream written to by the function.
     */
    virtual void virtualPrintAddedDetails(std::ostream& os) const;

    /**
     *
     * @param os - std::ostream type stream written to by the operator.
     * @param card - the card who's details are written to stream
     * @return - std::ostream type stream with the added card details.
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);


    /************ DEFAULT/DELETED METHODS ************/

    virtual ~Card() = default;
    Card(const Card&) = delete;
    Card& operator=(const Card& other) = delete;

protected:

    /**
     * C'tor of Card class (abstract class - will be inherited by specific type cards)
     *
     * @param name - The name of the card.
     * @return - A new instance of Card.
    */
    explicit Card(const std::string& name);


    /************ MEMBERS ************/

    std::string m_name;

};




#endif //EX4_Card_H
