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


    /**
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    * @exceptions that may be thrown:
        * std::bad_alloc - if an allocation of the game or of one of the cards/players was unsuccessful
        * DeckFileNotFound() - if deck address leads to a non-existing file
        * DeckFileFormatError() - if deck address leads to a bad-format file:
             1) a line contains a non-exist card name
             2) an empty line
             3) a line contains a char not in: "a..z,A..Z"
             4) a line contains more than 1 word
           what() will include the bad line of the deck file.
        * DeckFileInvalidSize() - if deck size < 5.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /**
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /**
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /**
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/**
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;



private:

    static const int INITIAL_ROUNDS_PLAYED = 0;
    static const int INITIAL_NUMBER_OF_PLAYERS = 0;
    static const int MIN_CARDS_ALLOWED = 5;
    static const int INITIAL_INDEX = 0;
    static const int USER_INPUT_MAX_LETTERS = 15;
    static const int USER_INPUT_VALID_NUM_WORDS = 2;
    static const int MIN_PLAYERS = 2;
    static const int MAX_PLAYERS = 6;
    enum Mode {player, card};

    const std::vector<std::string> playerTypes{"Healer", "Ninja", "Warrior"};
    const std::vector<std::string> cardTypes{"Witch", "Gremlin", "Dragon", "Mana", "Barfight", "Well", "Treasure", "Merchant"};
    const std::string permittedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string HEALER_STRING = "Healer";
    const std::string NINJA_STRING = "Ninja";
    const std::string WARRIOR_STRING = "Warrior";
    const std::string NO_CLASS_STRING = "NoClass";

    /** private members **/
    std::vector<std::unique_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Card>> m_cards;
    int m_roundsPlayed;
    int m_numberOfPlayers;
    int m_currentCardIndex;
    std::vector<int> m_winners;
    std::vector<int> m_losers;
    std::vector<int> m_activePlayers;


    void createDeck(const std::string &fileName); // check for all types of errors in the file, and throws them
    bool cardStringValid(const std::string &str) const;
    bool playerStringValid(const std::string &str) const;
    void createCard(const std::string &str);
    void enterValidUserPlayerLine();
    void createPlayer(const std::string& playerName, const std::string &playerClass);
    int checkUserPlayerName(const std::string& name, const std::string& userClass) const; ///updated test10
    int checkUserPlayerClass(const std::string& name) const;
    void checkUserInputLine(std::string& userLine,std::string& userName,std::string& userClass);
    int takeNumOfPlayers();
    void incrementCardIndex();
    void updateActivePlayers(const int &currentIndex);

};



#endif /* MTMCHKIN_H_ */
