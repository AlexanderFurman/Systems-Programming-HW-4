//
// Created by alex on 1/15/23.
//
#ifndef HW3_CLION_HEALER_H
#define HW3_CLION_HEALER_H

#include "Player.h"

/// child class derived from Player
class Healer : public Player
{
public:

    /**
     * constructor of Healer class
     * @param name - name of the player
     */
    explicit Healer(const std::string& name);

    /**
     * overides generic heal function from Player -> adds addedHP to the player twice, so long as total HP not over max.
     * @param addedHP - HP to be added to player
     */
    void heal(int addedHP) override;

    /**
     * overides generic getJob function from Player -> returns string of player's job
     * @param NONE
     */
    std::string getJob() const override;

    /************** DEFAULT/DELETED METHODS **************/
    ~Healer() override = default;

};


#endif //HW3_CLION_HEALER_H
