#include "gamestate.h"

#include <assert.h>
#include <iostream>

namespace {
    unsigned int score = 0;
}


Game::GameState::GameState()
{

}

Game::GameState::~GameState()
{

}


void Game::GameState::increaseScore()
{
    ++score;
    std::cout << score << std::endl;
}
