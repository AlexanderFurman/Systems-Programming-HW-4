//
// Created by alex on 1/15/23.
//

#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName)
{
    try
    {
        createDeck(fileName);
    }
    catch(const DeckFileNotFound& e)
    {
//        TODO: complete this
    }
    catch(const DeckFileFormatError& e)
    {
//        TODO: complete this
    }
    catch(const DeckFileInvalidSize& e)
    {
//        TODO: complete this
    }



}

void Mtmchkin::playRound()
{

}

void Mtmchkin::printLeaderBoard() const
{

}

bool Mtmchkin::isGameOver() const
{

}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundsPlayed;
}

void Mtmchkin::createDeck(const std::string &fileName)
{
    Mode cardMode = card;
    std::ifstream file(fileName);
    std::string currentLine;

    //Check if file does not exist
    if(file.fail())
    {
        throw DeckFileNotFound();
    }


    // check if all strings are valid card names
    while(std::getline(file, currentLine))
    {
        trimString(&currentLine);
        if (!stringValid(currentLine, cardMode))
        {
            throw DeckFileFormatError(m_cards.size(), currentLine);
        }
        createCard(currentLine);
    }

    //Too few cards
    if(m_cards.size() < MIN_CARDS_ALLOWED)
    {
        throw DeckFileInvalidSize();
    }
}

bool Mtmchkin::stringValid(const std::string &str, const enum Mode &mode)
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
            }
            return true;
    }
}

void Mtmchkin::createCard(const std::string &str)
{
    if (str == "Witch")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Witch()))
    }
    else if (str == "Gremlin")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Gremlin()))
    }
    else if (str == "Dragon")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Dragon()))
    }
    else if (str == "Mana")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Mana()))
    }
    else if (str == "Barfight")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Barfight()))
    }
    else if (str == "Well")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Well()))
    }
    else if (str == "Treasure")
    {
        m_cards.push_back(std::unique_ptr<Card>(new Treasure()))
    }
    else //Merchant
    {
        m_cards.push_back(std::unique_ptr<Card>(new Merchant()))
    }
}