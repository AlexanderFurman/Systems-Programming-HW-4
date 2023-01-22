//
// Created by alex on 1/15/23.
//

#include "Mtmchkin.h"
#include "Exception.h"
#include "utilities.h"
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"

/**
 * omer 18.1 - general notes:
 * !!!) added functions as not private to Mtmchkin - forbidden. https://piazza.com/class/l8vdfbb5pf86qf/post/496
 * **/


/*** static functions signatures ***/
static int countWordsAndRemoveDuplicateSpaces(std::string &str);



/*** Mtmchkin methods ***/

Mtmchkin::Mtmchkin(const std::string &fileName): m_roundsPlayed(INITIAL_ROUNDS_PLAYED), m_numberOfPlayers(INITIAL_NUMBER_OF_PLAYERS),
                                                 m_currentCardIndex(INITIAL_INDEX)
{
    printStartGameMessage();
    createDeck(fileName);
    m_numberOfPlayers = takeNumOfPlayers();
    for(int i=0; i<m_numberOfPlayers; i++)
    {
        enterValidUserPlayerLine();
    }
}

int Mtmchkin::takeNumOfPlayers()
{
    printEnterTeamSizeMessage();
    std::string userStr;
    int userNum;
    while (true)
    {
        std::getline(std::cin,userStr);
        try { ///updated test3
            userNum = std::stoi(userStr);
        }
        catch(...) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
        if(userNum < MIN_PLAYERS || userNum > MAX_PLAYERS)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
        return userNum;
    }
}


void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundsPlayed+1);
    for (int i = 0; i < int(m_players.size()); i++)
    {
        if (m_players[i]->isPlaying())
        {
            printTurnStartMessage(m_players[i]->getName());
            m_cards[m_currentCardIndex]->applyEncounter(m_players[i]);
            incrementCardIndex();
            if (m_players[i]->won())
            {
                m_winners.push_back(i);
            }
            else if (m_players[i]->isKnockedOut())
            {
                m_losers.insert(m_losers.begin(), i);
            }
        }
        updateActivePlayers(i);
    }
    m_roundsPlayed++;
    if(isGameOver()) { ///need to stop running game (play round) from main
        printGameEndMessage();
    }
}

void Mtmchkin::updateActivePlayers(const int &currentIndex)
{
    std::vector<int> activePlayers = {};
    if (currentIndex < int(m_players.size()) - 1)
    {
        for(int i=currentIndex+1; i < int(m_players.size()); i++)
        {
            if (m_players[i]->isPlaying())
            {
                activePlayers.push_back(i);
            }
        }
    }
    for (int i=0; i <= currentIndex; i++)
    {
        if (m_players[i]->isPlaying())
        {
            activePlayers.push_back(i);
        }
    }
    m_activePlayers = activePlayers;
}


void Mtmchkin::printLeaderBoard() const
{
    std::vector<int> leaderBoard = {};
    leaderBoard.insert(leaderBoard.end(), m_winners.begin(), m_winners.end());
    leaderBoard.insert(leaderBoard.end(), m_activePlayers.begin(), m_activePlayers.end());
    leaderBoard.insert(leaderBoard.end(), m_losers.begin(), m_losers.end());

    printLeaderBoardStartMessage();
    for (int i = 0; i<m_numberOfPlayers; i++)
    {
        printPlayerLeaderBoard(i+1, *(m_players[leaderBoard.at(i)].get()));
    }

}

bool Mtmchkin::isGameOver() const
{
    for (const std::unique_ptr<Player>& player : m_players)
    {
        if (player->isPlaying())
        {
            return false;
        }
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundsPlayed;
}

void Mtmchkin::incrementCardIndex()
{
    if (m_currentCardIndex < (int(m_cards.size()) - 1))
    {
        m_currentCardIndex ++;
    }
    else
    {
        m_currentCardIndex = 0;
    }
}

void Mtmchkin::createDeck(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string currentLine;
    int currentLineCount = 0;
    if(file.fail()) //Check if file does not exist
    {
        throw DeckFileNotFound();
    }
    while(std::getline(file, currentLine))  // check if all strings are valid card names
    {
        currentLineCount ++;
        std::string trimmedString = currentLine;
        countWordsAndRemoveDuplicateSpaces(trimmedString);

        if (!cardStringValid(trimmedString))
        {
            throw DeckFileFormatError(currentLineCount);
        }
        else
        {
            createCard(trimmedString);
        }
    }
    if(m_cards.size() < MIN_CARDS_ALLOWED)    //Too few cards
    {
        throw DeckFileInvalidSize();
    }
}

bool Mtmchkin::cardStringValid(const std::string &str) const
{
    for(const std::string& card : cardTypes)
    {
        if (str == card)
        {
            return true;
        }
    }
    return false;
}

bool Mtmchkin::playerStringValid(const std::string &str) const
{
        for(const char &character : str)
        {
            if (permittedCharacters.find(character) == std::string::npos)
            {
                return false;
            }
            if (str.length() > USER_INPUT_MAX_LETTERS)
            {
                return false;
            }
        }
        return true;
}

void Mtmchkin::createCard(const std::string &str)
{
    if (str == "Witch")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Witch()));
    }
    else if (str == "Gremlin")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Gremlin()));
    }
    else if (str == "Dragon")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Dragon()));
    }
    else if (str == "Mana")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Mana()));
    }
    else if (str == "Barfight")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Barfight()));
    }
    else if (str == "Well")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Well()));
    }
    else if (str == "Treasure")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Treasure()));
    }
    else ///Merchant
    {
        m_cards.push_back(std::unique_ptr<Card>(new Merchant()));
    }
}

void Mtmchkin::createPlayer(const std::string& userName, const std::string &userClass)
{
    if(userClass==HEALER_STRING)
    {
        m_players.push_back(std::unique_ptr<Player>(new Healer(userName)));
    }
    if(userClass==NINJA_STRING)
    {
        m_players.push_back(std::unique_ptr<Player>(new Ninja(userName)));
    }
    if(userClass==WARRIOR_STRING)
    {
        m_players.push_back(std::unique_ptr<Player>(new Warrior(userName)));
    }
}

/*** static functions implementations ***/
void Mtmchkin::enterValidUserPlayerLine()
{
    printInsertPlayerMessage();
    while(true)
    {
        std::string userName;
        std::string userClass;
        std::string userLine;
        std::getline(std::cin,userLine);
        try {
            checkUserInputLine(userLine,userName,userClass);
        }
        catch (const EmptyUserPlayerLine&) {
            continue;
        }
        catch (const InvalidUserPlayerName&) {
            printInvalidName();
            continue;
        }
        catch (const InvalidUserPlayerClass&) {
            printInvalidClass();
            continue;
        }
        createPlayer(userName,userClass);
        return;
    }
}


void Mtmchkin::checkUserInputLine(std::string& userLine,std::string& userName,std::string& userClass)
{
    std::string lineCopy = userLine;
    int numWords = countWordsAndRemoveDuplicateSpaces(lineCopy);
    if(userLine.empty() || !numWords) {
        throw EmptyUserPlayerLine();
    }
    int separatorIdx = int(lineCopy.find(' ')); //(lineCopy.find(' ')==std::string::npos) ? lineCopy.length() : lineCopy.find(' ');
    userName = std::string(lineCopy,0,separatorIdx);
    if(numWords!=USER_INPUT_VALID_NUM_WORDS) { ///updated test10
        userClass = NO_CLASS_STRING;
        if(checkUserPlayerName(lineCopy, userClass)) { ///updated test10
            throw InvalidUserPlayerClass();
        }
        else {
            throw InvalidUserPlayerName();
        }
    }
    else {
        userClass = std::string(lineCopy,++separatorIdx, std::string::npos);
        if(!checkUserPlayerName(userName,userClass)) { ///updated test10
            throw InvalidUserPlayerName();
        }
        else if (!checkUserPlayerClass(userClass)) {
            throw InvalidUserPlayerClass();
        }
        return;
    }
}



int Mtmchkin::checkUserPlayerName(const std::string& name, const std::string& userClass) const
{
    int len = int(name.length());
    if(len>USER_INPUT_MAX_LETTERS || len < 1 || !playerStringValid(name)) {
        return false;
    }
    for(const std::unique_ptr<Player>& player : m_players)
    {
        if (name == player->getName()) {
            if(userClass == NO_CLASS_STRING || player->getJob() == userClass) { ///updated test10
                return false;
            }
        }
    }
    return true;
}


int Mtmchkin::checkUserPlayerClass(const std::string& name) const
{
    for(const std::string& str : playerTypes )
    {
        if (name == str) {
            return true;
        }
    }
    return false;
}

static int countWordsAndRemoveDuplicateSpaces(std::string &str) {
    int wordCount = 0;
    int i = 0;
    while (str[i]) {
        if(str[i] == ' ') {
            i++;
        }
        while (str[i] == ' ') {
            str.erase(i, 1);
        }
        if (str[i] != ' ' && str[i]) {
            wordCount++;
        }
        while (str[i] != ' ' && str[i]) {
            i++;
        }
    }
    if(str[i-1]==' ') {
        str.erase(i-1, 1);
    }
    if(str[0]==' ') {
        str.erase(0, 1);
    }
    return wordCount;
}



