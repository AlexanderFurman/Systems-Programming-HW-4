//
// Created by alex on 1/19/23.
//

#include "Players/Player.h"
#include <queue>
#include <memory>

#ifndef HW3_CLION_LEADERBOARD_H
#define HW3_CLION_LEADERBOARD_H

class LeaderBoard
{
private:
    std::vector<int> m_winners;
    std::vector<int> m_losers;
    std::vector<std::shared_ptr<Player>> m_players;

public:

    explicit LeaderBoard(std::vector<std::shared_ptr<Player>> &players);

    void addWinner(std::shared_ptr<Player> &player);

    void addLoser(std::shared_ptr<Player> &player);

    const std::vector<std::shared_ptr<Player>> getOrder();


};


#endif //HW3_CLION_LEADERBOARD_H

