#include "gamestate.h"

#include <assert.h>
#include <iostream>

#define TIMER_MAX 5000
#define TIMER_MIN 150


Game::GameState::GameState() :
    QObject(nullptr),
    score(0),
    timerMax(TIMER_MAX),
    timer(new QTimer())
{
    connect(timer, SIGNAL(timeout()), this, SLOT(timedOut()));
    timer->start(1000);
}


Game::GameState::~GameState()
{
    delete timer;
}


void Game::GameState::increaseScore()
{
    ++score;
    std::cout << score << std::endl;
}


unsigned int Game::GameState::getScore()
{
    return score;
}


QTimer *Game::GameState::getTimer() {
    return timer;
}


void Game::GameState::reset()
{

}


void Game::GameState::timedOut() {
    std::cout << "Timed out!" << std::endl;
}
