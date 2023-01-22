//
// Created by alex on 1/15/23.
//

#ifndef HW3_CLION_WARRIOR_H
#define HW3_CLION_WARRIOR_H

#include "Player.h"

/// child class derived from Player
class Warrior : public Player
{
public:

    /**
     * constructor of Warrior class
     * @param name - name of the player
     */
    explicit Warrior(const std::string& name);


    /**
     * overides generic getAttackStrength function from Player ->
     * double the force.
     * @param NONE
     * @returns int of attack strength of player
     */
    int getAttackStrength() const override;

    /**
     * overides generic getJob function from Player
     * @param NONE
     * @returns  string of player's job
     */
    std::string getJob() const override;

    /************** DEFAULT/DELETED METHODS **************/
    ~Warrior() override = default;

};

#endif //HW3_CLION_WARRIOR_H
