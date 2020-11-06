#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>
#include <QTimer>


// NOTE: not using QT_BEGIN_NAMESPACE because it's unecessary

namespace Game {


/**
 * @brief The GameState class. Inherits from QObject for
 */
class GameState : public QObject
{

Q_OBJECT


signals:
    void timeOut();
    void timeRemaining(int remaining);

private:

    bool active;

    unsigned int score;

    unsigned int timerMax;  // Max for the timer. Will decrease every tick.

    QTimer *timer;
    QTimer *updateTimer;

    void resetTime();


private slots:
    void timedOut();
    void updateTime();

public:
    /**
     * @brief GameState constructor.
     */
    GameState();


    ~GameState();

    /**
     * @brief Increases score by 1
     */
    void increaseScore();


    unsigned int getScore();


    /**
     * @brief getTimer
     * @return QTimer *
     */
    QTimer *getTimer();


    /**
     * @brief Starts a game.
     */
    void startGame();

    /**
     * @brief Resets game state. Score goes to 0, and timer resets.
     */
    void reset();


    bool isActive();
};
}


#endif // GAMESTATE_H
