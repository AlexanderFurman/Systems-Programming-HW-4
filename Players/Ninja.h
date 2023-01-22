//
// Created by alex on 1/14/23.
//

#ifndef HW3_CLION_NINJA_H
#define HW3_CLION_NINJA_H

#include "Player.h"

/// child class derived from Player
class Ninja : public Player
{
public:

    /**
     * constructor of Healer class
     * @param name - name of the player
     */
    explicit Ninja(const std::string& name);

    /**
     * overides generic addCoins function from Player -> adds addedCoins to the player twice,
     * so long as total coins not over max.
     * @param addedCoins - coins to be added to player
     */
    void addCoins(int addedCoins) override;

    /************** DEFAULT/DELETED METHODS **************/
    std::string getJob() const override;
    ~Ninja() override = default;
};

#endif //HW3_CLION_NINJA_H
