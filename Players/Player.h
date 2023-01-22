//
// Created by alex on 1/14/23.
//

#ifndef HW3_CLION_PLAYER_H
#define HW3_CLION_PLAYER_H

#include <string>
#include <iostream>

class Player
{
public:

    /// static integer values to be used in constructors + functions
    static const int MAX_HP = 100;
    static const int MAX_LEVEL = 10;
    static const int NEW_PLAYER_LEVEL = 1;
    static const int NEW_PLAYER_FORCE = 5;
    static const int NEW_PLAYER_COINS = 10;
    static const int DOUBLE = 2;

    /**
     * constructor of Player class
     * @param name - name of the player
     */
    explicit Player(const std::string& name); ///should it be string& or by value?
//            m_name(name), m_level(NEW_PLAYER_LEVEL), m_force(NEW_PLAYER_FORCE),
//            m_maxHP(MAX_HP), m_HP(MAX_HP), m_coins(NEW_PLAYER_COINS) {}


    virtual ~Player() = default;

    /*** setters and getters: ***/

    /**
     * @param NONE
     * @returns  int of attack strength of player
     */
    virtual int getAttackStrength() const;

    /**
     * @param NONE
     * @returns  string of name of player
     */
    const std::string& getName() const;


    /**
     * @param NONE
     * @returns  level of player
     */
    int getLevel() const ;

    /**
     * @param NONE
     * @returns  force of player
     */
    int getForce() const;

    /**
     * @param NONE
     * @returns  HP of player
     */
    int getHP() const;

    /**
     * @param NONE
     * @returns  number of coins of player
     */
    int getCoins() const;

    /*** other required methods ***/
    /// if methods get neg/wrong value treat as got 0

    /**
     * @param deductedHP - the number of points to remove from player's HP - so long as non-negative HP remains
     */
    void damage(int deductedHP);

    /**
     * increases the player's level, so long as less than max level
     * @param None
     */
    void levelUp();

    /**
     * returns if player has lost the game
     * @param None
     */
    bool isKnockedOut() const;

    /**
     * returns if player has won the game
     * @param None
     */
    bool won() const;

    /**
     * deducts from player's coins
     * @param deductedCoins - number of coins to remove
     * @returns  bool - if false, no payment occured
     */
    bool pay(int deductedCoins);

    /**
     * adds to player's coins
     * @param addedCoins - number of coins to add
     */
    virtual void addCoins(int addedCoins);

    /**
     * adds to player's force
     * @param forceIncrease - number of points to add to force
     */
    virtual void buff(int forceIncrease);

    /**
     * adds to player's HP
     * @param addedHP - number of points to add to player's HP, added until max HP reached
     */
    virtual void heal(int addedHP);

    /**
     * decreases player's force by 1, unless force is already at minimum
     * @param NONE
     */
    void decForce(); ///added by omer - 16.1

    /**
     * @param NONE
     * @returns bool - if player has not won, and also has not lost
     */
    bool isPlaying() const;

    /**
     * pure virtual method which must be overridden
     * @param NONE
     * @returns  string of player's job
     */
    virtual std::string getJob() const = 0; //purely virtual

    /**
     * overides << method, used for printing player information
     * @param os - the stream to which the string will be printed to
     * @param player - the player whose details will be printed
     * @returns  os - the stream which contains the message of the player
     */
    friend std::ostream& operator<<(std::ostream & os, const Player& player);


protected:
    std::string m_name; ///english letters (Aa), no spaces, less than 15 chars
    int m_level; /// int in range 1..10
    int m_force; /// int >= 0
    int m_maxHP; /// int > 0
    int m_HP; /// int in range 0..maxHP
    int m_coins; /// int >= 0

};

#endif //HW3_CLION_PLAYER_H
