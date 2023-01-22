//
// Created by alex on 1/22/23.
//

#include <iostream>
#include "../Mtmchkin.h"
#include <exception>

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try
    {
        Mtmchkin game("deck.txt");

        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
        {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }

    return 0;
}