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
    const int INITIAL_INDEX = 0;

    ///omer 18.1: we can figure with ascii codes: if( (c>='a' && c<='z') || (c>='A' && c<='Z') )
    const std::string permittedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    ///omer 18.1: static consts?
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
    ///omer 18.1: how do we implement using queue? we can't push players out.
    ///omer 18.1: how do we implement curPlayer is pointer to player?.
    std::vector<std::unique_ptr<Player>> m_players; ///omer 18.1: queue->vector, unique->shared --why does it need to be shared here? -- also, should be queue
    std::vector<std::unique_ptr<Card>> m_cards;
    int m_roundsPlayed;
    int m_numberOfPlayers;
    int m_currentIndex;
    int m_currentPlayerIndex;
    std::vector<int> m_winners;
    std::vector<int> m_losers;
    std::vector<int> m_activePlayers;

    //internal use functions
    void createDeck(const std::string &fileName); // check for all types of errors in the file, and throws them
    bool stringValid(const std::string &str, const enum Mode &mode);
    void createCard(const std::string &str);
    void removeSpaces(std::string &str);
    ///18.1 omer added:
    void enterValidUserPlayerLine();
    void createPlayer(const std::string &playerName, const std::string &playerClass);
    int checkUserPlayerName(const std::string& name);
    int checkUserPlayerClass(const std::string& name);
    void checkUserInputLine(std::string& userLine,std::string& userName,std::string& userClass)
    std::string removeStringDuplicateSpaces(const std::string& userLine);

    ///19.1 alex added:
    void incrementIndex();
    void updateActivePlayers(const int &currentIndex);




};



#endif /* MTMCHKIN_H_ */
