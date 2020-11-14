#include "gamestate.h"

#include <assert.h>
#include <iostream>
#include <random>

#define TIMER_MAX_INTERVAL    5000
#define TIMER_MIN_INTERVAL    150
#define UPDATE_TIMER_INTERVAL 5

#define MAX_INPUTS_ACTIVE     7 // max number of inputs to be generated


Game::GameState::GameState() :
    QObject(nullptr),
    active(false),
    score(0),
    timerMax(TIMER_MAX_INTERVAL),
    timer(new QTimer()),
    updateTimer(new QTimer())
{
    connect(timer, SIGNAL(timeout()), this, SLOT(timedOut()));
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateTime()));

    generate();
}


Game::GameState::~GameState()
{
    delete timer;
}


void Game::GameState::nextLevel()
{
    generate();
    // TODO: update the max for the timer.
}


void Game::GameState::increaseScore()
{
    ++score;

#ifdef QT_DEBUG
    std::cout << score << std::endl;
#endif
}


unsigned int Game::GameState::getScore()
{
    return score;
}


void Game::GameState::startGame()
{
    this->generate();
    active = true;
    timer->start(TIMER_MAX_INTERVAL);
    updateTimer->start(UPDATE_TIMER_INTERVAL);
}


void Game::GameState::resetTimer()
{
    timer->stop();
    updateTimer->stop();
}


bool Game::GameState::isActive()
{
    return active;
}


void Game::GameState::timedOut()
{
    std::cout << "Timed out!" << std::endl;
    // TODO: reset things.

    emit gameOverSignal(score);
    resetTimer();
}


void Game::GameState::updateTime()
{
    emit timeRemainingSignal(timer->remainingTime());
}


void Game::GameState::generate()
{
    input = (Game::INPUT)(rand() % 8);
    negation = (Game::NEGATION)(rand() % 4);
    assert(input <= Game::RIGHT);  // These should always pass, but just in case...
    assert(negation <= Game::NOTNOTNOT);


    // Reset the timer
    timer->start(TIMER_MAX_INTERVAL);
    updateTimer->start(UPDATE_TIMER_INTERVAL);

    emit generateLevelSignal();
}


void Game::GameState::processInput(Game::INPUT input)
{

    bool negate = negation % 2;
    if ((input == this->input) == !negate) {
        increaseScore();
        nextLevel(); // Next level
    } else { // Game over
        resetTimer();
        emit gameOverSignal(score);
    }
}


void Game::GameState::reset()
{

}


Game::INPUT Game::GameState::getInput()
{
    return input;
}


Game::NEGATION Game::GameState::getNegation()
{
    return negation;
}
