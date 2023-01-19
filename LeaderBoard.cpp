//
// Created by alex on 1/19/23.
//

#include "LeaderBoard.h"

LeaderBoard::LeaderBoard(std::vector<std::shared_ptr<Player>> &players): m_winners({}), m_losers({})
{
    for (int i = 0; i < players.size(); i++)
    {
        m_players.push_back(players[i]);
    }
}

void LeaderBoard::addWinner(std::shared_ptr<Player> &player)
{
    m_winners.push_back(player);
}

void LeaderBoard::addLoser(std::shared_ptr<Player> &player)
{
    m_losers.push_back(player);
}

const std::vector<std::shared_ptr<Player>> LeaderBoard::getOrder()
{
    std::vector<std::shared_ptr<Player>> order;


}
