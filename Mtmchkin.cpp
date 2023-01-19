//
// Created by alex on 1/15/23.
//

#include "Mtmchkin.h"
#include "Exception.h"

/**
 * omer 18.1 - general notes:
 * 1) static functions for internal mtmchkin.cpp use? (instead of methods)
 * 2) added functions as not private to Mtmchkin - forbidden. https://piazza.com/class/l8vdfbb5pf86qf/post/496
 * 3) charachters and strings by value? like: ' ' for space. is it ok? (i used it too)
 * **/


/*** static functions signatures ***/
static int countWordsAndRemoveDuplicateSpaces(std::string &str);



/*** Mtmchkin methods ***/

Mtmchkin::Mtmchkin(const std::string &fileName): m_roundsPlayed(INITIAL_ROUNDS_PLAYED), m_numberOfPlayers(INITIAL_NUMBER_OF_PLAYERS),
m_currentIndex(INITIAL_INDEX)
{
    //  SHOULD THIS BE CAUGHT HERE OR SOMEWHERE ELSE? MAYBE IN MAIN?
    try
    {
        createDeck(fileName);
    }
    catch(const DeckFileNotFound& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const DeckFileFormatError& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const DeckFileInvalidSize& e)
    {
        std::cout << e.what() << std::endl;
    }
    ///omer 18.1: resume - add get team size + prints..
    ///omer 18.1: need to add - add player func. using while and: enterValidUserPlayerLine()
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundsPlayed+1);
//    for (const std::shared_ptr<Player>& player : m_players)
    for (int i = 0; i < m_players.size(); i++)
    {
        std::shared_ptr<Player>& player = m_players.front();
        m_players.erase(m_players.begin());
        printTurnStartMessage(player->getName());
        m_cards[m_currentIndex]->applyEncounter(player.get()); /// There is an issue here since the function takes a pointer -- can it accept unique/shared ptrs?
        incrementIndex();

        if (!player->isPlaying())
        {
            m_players.push_back(player);
        }
        else if (player->won())
        {
            m_leaderBoard.addWinner(player.get());
        }
        else
        {
            m_leaderBoard.addLoser(player.get());
        }

    }
    m_roundsPlayed++;
}

void Mtmchkin::printLeaderBoard() const
{

}

bool Mtmchkin::isGameOver() const
{
    for (const std::shared_ptr<Player>& player : m_players)
    {
        if (player->isPlaying())
        {
            return false;
        }
    }

}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundsPlayed;
}

void Mtmchkin::incrementIndex()
{
    if (m_currentIndex < (m_cards.size() - 1))
    {
        m_currentIndex ++;
    }
    else
    {
        m_currentIndex = 0;
    }
}

void Mtmchkin::createDeck(const std::string &fileName)
{
    Mode cardMode = card;
    std::ifstream file(fileName);
    std::string currentLine;
    int currentLineCount = 0;

    //Check if file does not exist
    if(file.fail())
    {
        throw DeckFileNotFound();
    }


    // check if all strings are valid card names
    while(std::getline(file, currentLine))
    {
        currentLineCount ++; ///omer 18.1: should it be in start? or end of func? (start from 1 or 0?) --> We start from line 1, no line 0 so I think it should be 1
        std::string trimmedString = currentLine;
        removeSpaces(trimmedString); ///omer 18.1: why to remove spaces? a line like: "Ma na" is legal? also what about newline? didn't understand. --> You are correct - I changed the code

        //If there is some newline, we simple move to the next line
        if (trimmedString == ""){}
        else if (!stringValid(trimmedString, card))
        {
            throw DeckFileFormatError(currentLineCount); ///omer 18.1: currentLineCount used here
        }
        else
        {
            createCard(trimmedString);
        }
    }

    //Too few cards
    if(m_cards.size() < MIN_CARDS_ALLOWED)
    {
        throw DeckFileInvalidSize();
    }
}

///omer 18.1 - check length<=15? --> you are right, I am changing the code
///alex 19.1 - mode enum not necessary - I am removing it -- > should I add to check PlayerType is also valid here?
//bool Mtmchkin::stringValid(const std::string &str, const enum Mode &mode)
bool Mtmchkin::stringValid(const std::string &str, const Mode &mode)
{
    switch(mode)
    {
        case card:
            for(const std::string& card : cardTypes)
            {
                if (str == card)
                {
                    return true;
                }
            }
            return false;

        case player:
            for(const char &character : str)
            {
                if (permittedCharacters.find(character) == std::string::npos)
                {
                    return false;
                }
                if (str.length() > 15)
                {
                    return false;
                }
            }
        return true;
//    }
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
    else //Merchant
    {
        m_cards.push_back(std::unique_ptr<Card>(new Merchant()));
    }
}

void Mtmchkin::removeSpaces(std::string &str)
{
//    for (int i = 0; i < str.length(); i++)
//    {
//        if (str[i] == ' ')
//        {
//            str.erase(i,1);
//        }
//    }

    // removes white spaces at beginning and end of line
    while (str.length() > 0)
    {
        if(str[0] == ' ')
        {
            str.erase(0,1);
        }
        if(str[str.length()-1] == ' ')
        {
            str.erase(str.length()-1,1);
        }
    }
}

/*** static functions implementations ***/
//check if player exists: just name? or name+character?
void Mtmchkin::enterValidUserPlayerLine()
{
    printInsertPlayerMessage();
    while(true)
    {
        std::string userName = "";
        std::string userClass = "";
        std::string userLine;
        std::cin >> userLine;
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
    int separatorIdx = lineCopy.find(' '); //(lineCopy.find(' ')==std::string::npos) ? lineCopy.length() : lineCopy.find(' ');
    userName = std::string(lineCopy,0,separatorIdx);
    if(numWords!=2) {
        if(checkUserPlayerName(lineCopy)) {
            throw InvalidUserPlayerClass();
        }
        else {
            throw InvalidUserPlayerName();
        }
    }
    else {
        // int startOfClass = separatorIdx+1;
        userClass = std::string(lineCopy,++separatorIdx, std::string::npos);
        if(!checkUserPlayerName(userName)) {
            throw InvalidUserPlayerName();
        }
        else if (!checkUserPlayerClass(userClass)) {
            throw InvalidUserPlayerClass();
        }
        return;
    }
}




//* Additions removed from enterValidUserPlayerLine():
//
//        int numSpaces = std::count(lineCopy.begin(), lineCopy.end(), ' ');
//        if (numSpaces==0) {
//            printInvalidName();
//            continue;
//        }
//        ///how to check strings? need to check if more then two words in the string!!
//
//
//        int separatorIndex = lineCopy.find(' ');
//        if(separatorIndex==std::string::npos)
//        {
//            try{
//                checkUserPlayerName(lineCopy);
//            }
//        }
//        std::string userName = std::string(lineCopy,0,separatorIndex-1);
//        std::string userClass = std::string(lineCopy,separatorIndex, std::string::npos);
//        if (!checkUserPlayerName(userName) || !checkUserPlayerClass(userClass))
//        {
//            continue;
//        }
//
//
//

// *//


int Mtmchkin::checkUserPlayerName(const std::string& name)
{
    int len = name.length();
    if(len>15 || len < 1 || !(Mtmchkin::stringValid(name,player))) {
        return false;
    }
    for(std::shared_ptr<Player> p : m_players )
    {
        if(p== nullptr) { //omer 18.1: if enters here - no more players in vector yet
            break;
        }
        if (name == p->getName()) {
            return false;
        }
    }
    return true;
}

int Mtmchkin::checkUserPlayerClass(const std::string& name)
{
    for( std::string str : playerTypes )
    {
        if (name == str) {
            return false;
        }
    }
    return true;
}

static int countWordsAndRemoveDuplicateSpaces(std::string &str) {
    int wordCount;
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


//    i++;
//    while (str[i] == ' ' )
//    {
//        str.erase(i,1);
//    }
//    while (str[i] != ' ')
//    {
//        i++;
//    }
//    while (str[i] == ' ' )
//    {
//        str.erase(i,1);
//    }
//    if (str[i]) { //if more then 2 words
//        return false;
//    }
//    return true;
//}
//
//static int checkNumWords(std::string &str)
//{
//    int i = 0;
//    int wordCount = 0;
//    while (str[i] == ' ' )
//    {
//        i++;
//    }
//
//    while (str[i] != ' ')
//    {
//        i++;
//    }
//    i++;
//    while (str[i] == ' ' )
//    {
//        str.erase(i,1);
//    }
//    while (str[i] != ' ')
//    {
//        i++;
//    }
//    while (str[i] == ' ' )
//    {
//        str.erase(i,1);
//    }
//}
//
//std::string takeFirstWordFromLine(std::string userLine)
//{
//    int i=0;
//    while(userLine[i] == ' ')
//    {
//        userLine.erase(i,1);
//    }
//    while(userLine[i] != ' ')
//    {
//        userLine.erase(i,1);
//    }
//}



////checkUserInputLine() explenation:
////return string: valid input
////return empty string: not valid without print
////exceptions: not valid with print.
//std::string Mtmchkin::checkUserInputLine(std::string &str)
//{
//
//}




