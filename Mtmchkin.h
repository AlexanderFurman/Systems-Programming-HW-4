#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <queue>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>

class Mtmchkin{

public:

    const int MIN_PLAYERS = 2;
    const int MAX_PLAYERS = 6;
    const int INITIAL_ROUNDS_PLAYED = 0;
    const int INITIAL_NUMBER_OF_PLAYERS = 0;
    const int MIN_CARDS_ALLOWED = 5;

    const std::string permittedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const std::list<std::string> cardTypes{"Witch", "Gremlin", "Dragon", "Mana", "Barfight", "Well", "Treasure", "Merchant"};
    const std::list<std::string> playerTypes{"Healer", "Ninja", "Warrior"};
    enum Mode {player, card};

//    enum CardType {Witch, Gremlin, Dragon, Mana, Barfight, Well, Treasure, Merchant};
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;






private:
    std::queue<std::unique_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Card>> m_cards;
    int m_roundsPlayed;
    int m_numberOfPlayers;

    //internal use functions
    void createDeck(const std::string &fileName); // check for all types of errors in the file, and throws them
    bool stringValid(const std::string &str, const enum Mode &mode);
    void createCard(const std::string &str);
    void removeSpaces(std::string &str);
};



#endif /* MTMCHKIN_H_ */
