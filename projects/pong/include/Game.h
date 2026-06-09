#pragma once

enum class GameState
{
    MENU,
    PVE,
    PVP,
    GAMEOVER
};

class Game
{
private:
    int w_width;
    int w_height;
    GameState current_state;

    void update();
    void draw();

public:
    Game();
    Game(int window_width, int window_height);
    void run();
};
