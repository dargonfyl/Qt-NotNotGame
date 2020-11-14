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


void Game::GameState::increaseScore()
{
    ++score;
    std::cout << score << std::endl;
    generate(); // Next level
}


unsigned int Game::GameState::getScore()
{
    return score;
}


void Game::GameState::startGame() {
    this->generate();

    timer->start(TIMER_MAX_INTERVAL);
    updateTimer->start(UPDATE_TIMER_INTERVAL);
}


void Game::GameState::reset()
{
    score = 0;
    timer->stop();
    updateTimer->stop();
}


bool Game::GameState::isActive() {
    return active;
}


void Game::GameState::timedOut() {
    std::cout << "Timed out!" << std::endl;
    // TODO: reset things.

    emit gameOver(score);
    reset();
}


void Game::GameState::updateTime() {
    emit timeRemaining(timer->remainingTime());
}


void Game::GameState::generate() {
    input = (Game::INPUT)(rand() % 8);
    negation = (Game::NEGATION)(rand() % 4);
    assert(input <= Game::RIGHT);  // These should always pass, but just in case...
    assert(negation <= Game::NOTNOTNOT);

    emit generateLevel();
}


Game::INPUT Game::GameState::getInput() {
    return input;
}


Game::NEGATION Game::GameState::getNegation() {
    return negation;
}
