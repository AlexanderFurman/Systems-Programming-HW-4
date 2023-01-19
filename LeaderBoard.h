//
// Created by alex on 1/19/23.
//

#include "Players/Player.h"
#include <vector>

#ifndef HW3_CLION_LEADERBOARD_H
#define HW3_CLION_LEADERBOARD_H

class LeaderBoard
{
private:
    std::vector<Player*> m_winners;
    std::vector<Player*> m_losers;
    std::vector<Player*> m_playing;


};


#endif //HW3_CLION_LEADERBOARD_H
