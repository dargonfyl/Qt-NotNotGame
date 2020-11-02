#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace Game {
enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW
};
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};


class GameState
{
public:
    GameState();
    ~GameState();

    static void increaseScore();
};
}


#endif // GAMESTATE_H
