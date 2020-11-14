#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>
#include <QTimer>


// NOTE: not using QT_BEGIN_NAMESPACE because it's unecessary

namespace Game {


enum INPUT {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    UP,
    DOWN,
    LEFT,
    RIGHT
};


enum NEGATION {
    NONE,
    NOT,
    NOTNOT,
    NOTNOTNOT
};


/**
 * @brief The GameState class. Inherits from QObject for signals and slots.
 */
class GameState : public QObject
{

Q_OBJECT


signals:
    void timeOut();
    void timeRemaining(int remaining);
    void generateLevel();
    void gameOver(unsigned int finalScore);

private:
    bool active;


    unsigned int score;


    unsigned int timerMax;  // Max for the timer. Will decrease every tick.

    INPUT input;  // TODO: change this to a byte
    NEGATION negation;

    QTimer *timer;
    QTimer *updateTimer;


    void resetTime();


private slots:
    /**
     * @brief Slot for when primary timer runs out
     */
    void timedOut();


    /**
     * @brief Slot for updating the timer visual on the UI
     */
    void updateTime();


    /**
     * @brief Generate a level for the game.
     */
    void generate();


//    void processInput(int input);


public:
    /**
     * @brief GameState constructor.
     */
    GameState();


    /**
     * @brief Deconstructor
     */
    ~GameState();


    /**
     * @brief Increases score by 1
     */
    void increaseScore();


    /**
     * @brief getScore
     * @return score
     */
    unsigned int getScore();


    /**
     * @brief Starts a game.
     */
    void startGame();


    /**
     * @brief Resets game state. Score goes to 0, and timer resets.
     */
    void reset();


    /**
     * @brief isActive
     * @return isActive
     */
    bool isActive();



    INPUT getInput();


    NEGATION getNegation();
};
}


#endif // GAMESTATE_H
