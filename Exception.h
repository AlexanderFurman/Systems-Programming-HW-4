//
// Created by alex on 1/15/23.
//

#ifndef HW3_CLION_EXCEPTION_H
#define HW3_CLION_EXCEPTION_H

#include <exception>
#include <string>

/**
 * an exception for non-valid Player name-input from user
 */
class InvalidUserPlayerName : public std::exception{};

/**
 * an exception for non-valid Player class-input from user
 */
class InvalidUserPlayerClass : public std::exception {};

/**
 * an exception for non-valid Player line-input from user (not name or class)
 */
class EmptyUserPlayerLine : public std::exception {};

/**
 * an exception for intercepting an address to a non-existing file
 */
class DeckFileNotFound : public std::exception
{
public:
    /// what() override
    const char * what () const throw () override
    {
        return "Deck File Error: File not found";
    }
};

/**
 * an exception for intercepting an address to a bad-format file
 */
class DeckFileFormatError : public std::exception
{
private:
    std::string m_msg;

public:
    ///what() override - includes line where exception was thrown
    explicit DeckFileFormatError(const int &lineError) // : m_lineError(lineError)
    {
        m_msg = "Deck File Error: File format error in line " + std::to_string(lineError);
    };

    const char * what () const throw () override
    {
    return m_msg.c_str();
    }
};

/**
 * an exception for intercepting an address to a deck with less than 5 cards
 */
class DeckFileInvalidSize : public std::exception
{
public:
    const char * what () const throw () override
    {
        return "Deck File Error: Deck size is invalid";
    }

};

#endif //HW3_CLION_EXCEPTION_H

