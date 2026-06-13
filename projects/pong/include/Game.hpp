#pragma once

#include "Ball.hpp"
#include "Paddle.hpp"

enum class GameState
{
    MENU,
    PVE,
    PVP,
    GAME_OVER
};

class Game
{
private:
    int w_width;
    int w_height;
    GameState current_state;
    Ball ball;
    Paddle p1, p2;

    void init();
    void update();
    void draw();

public:
    Game();
    Game(int window_width, int window_height);
    void run();
};
