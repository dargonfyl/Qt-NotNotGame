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

private:
    unsigned int score;

    unsigned int timerMax;  // How much time is left

    QTimer *timer;

    void resetTime();

private slots:
    void timedOut();

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


    QTimer *getTimer();

    /**
     * @brief Resets game state. Score goes to 0.
     */
    void reset();
};
}


#endif // GAMESTATE_H
