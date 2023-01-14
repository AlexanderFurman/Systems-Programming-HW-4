//
// Created by alex on 1/14/23.
//

#ifndef HW3_CLION_PLAYER_H
#define HW3_CLION_PLAYER_H

#include <string>

typedef int PlayerLevel; /// natural number between 1 to 10

//Abstract Base Class
class Player {
public:

    static const int NEW_PLAYER_FORCE = 5;
    static const int NEW_PLAYER_MAXHP = 100;
    static const int PLAYER_MAX_LEVEL = 10;



    explicit Player(const std::string& name, int maxHP=100, int force=5): ///should it be string& or by value?
            m_name(name), m_level(1), m_force(force),
            m_maxHP(maxHP), m_HP(maxHP), m_coins(0)
    {
        if (maxHP<=0) {
            m_maxHP = NEW_PLAYER_MAXHP;
            m_HP = NEW_PLAYER_MAXHP;
        }
        if (force<0) {
            m_force = NEW_PLAYER_FORCE;
        }
    }
    ~Player() = default;
    Player(const Player& player) = default;
    Player& operator=(const Player& player) = default;

    /*** setters and getters: ***/

    int getAttackStrength() const/// return force+level
    {
        return m_force+m_level;
    }
    const std::string& getName() const
    {
        return m_name; // This should return *char instead of std__string, in oredr to match with the method printPlayerInfo
    }
    PlayerLevel getLevel() const // required
    {
        return m_level;
    }
    int getForce() const
    {
        return m_force;
    }

//    int getMaxHP() const;

    int getHP() const
    {
        return m_HP;
    }
    int getCoins() const
    {
        return m_coins;
    }

    /*** other required methods ***/
    /// if methods get neg/wrong value treat as got 0
    void damage(int deductedHP)
    {
        if(deductedHP<=0) {
            return;
        }
        m_HP = (m_HP-deductedHP<0) ? 0 : m_HP-deductedHP;
    }
    void levelUp()
    {
        if(m_level < PLAYER_MAX_LEVEL) {
            m_level++;
        }
    }
    bool isKnockedOut() const
    {
        return (m_HP==0);
    }
    bool won() const
    {
        return getLevel() == PLAYER_MAX_LEVEL;
    }
    bool pay(int deductedCoins) ///if false - not committing payment.
    {
        if(deductedCoins<=0) { //piazza @205
            return true;
        }
        if(m_coins-deductedCoins<0) { // doesn't have enough coins
            return false;
        }
        m_coins = m_coins-deductedCoins; // has enough coins
        return true;
    }

    //Virtual methods which must be implemented in the derived classes
    virtual void printInfo() const;

    void addCoins(int addedCoins)
    {
        m_coins += (addedCoins<=0) ? 0 : addedCoins;
    }
    void buff(int forceIncrease)
    {
        if(forceIncrease > 0) {
            m_force += forceIncrease;
        }
    }
    void heal(int addedHP) ///increase HP by addedHP with. total max value of maxHP.
    {
        if(addedHP<=0) {
            return;
        }
        m_HP = (m_HP+addedHP>=m_maxHP) ? m_maxHP : m_HP+addedHP;
    }


//private:
protected:
    std::string m_name; ///english letters (Aa), no spaces.
    PlayerLevel m_level; /// int in range 1..10
    int m_force; /// int >= 0
    int m_maxHP; /// int > 0
    int m_HP; /// int in range 0..maxHP
    int m_coins; /// int >= 0

};

#endif //HW3_CLION_PLAYER_H
