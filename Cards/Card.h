//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"
#include "Exception.h"
#include "CardStats.h"

///*
// *  CardType:
// *  Each card has a type:
// *  Gremlin, Witch, Dragon - Battle against a monster.
// *  Merchant - Increase current player's force/HP for money.
// *  Treasure - current player gets 10 coins.
// *  Well - current player loses 10 HP unless he's a Ninja.
// *  Barfight - current player loses 10 HP unless he's a Warrior.
// *  Mana - if current player is a Healer, Increase HP by 10 points - which means 20 for Healer (no more than maxHP points).
//*/
enum class AllowedCards {Gremlin, Witch, Dragon, Merchant, Treasure, Well, Barfight, Mana}; // The type of the Card

class Card {
public:


    virtual const std::string& getName() const = 0;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param curPlayer - The current player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player* curPlayer) const = 0; ///omer 16.1: const method?

    virtual std::ostream& virtualPrintCard(std::ostream& os) const {};

    friend std::ostream& operator<<(std::ostream& os, const Card* card);


//    /*
//     * Prints the card info:
//     *
//     * @return
//     *      void
//    */
//    void printInfo() const;


//    /*
//     * C'tor to the "default card" - Treasure card that gives 0 coins
//    */
//    Card(): m_effect(CardType::Treasure), m_stats() {}


    /*
     * default / deleted
    */
    ///omer 14/1: need for exception handling?
    virtual ~Card() = default;
    Card(const Card&) = delete; ///???
    Card& operator=(const Card& other) = delete; ///???

protected:
    /*
 * C'tor of Card class
 *
 * @param name - The name of the card.
 * @return
 *      A new instance of Card.
*/
    Card(const std::string& name);
    std::string m_name;

private:

};




#endif //EX4_Card_H
