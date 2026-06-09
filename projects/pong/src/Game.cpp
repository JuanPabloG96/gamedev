#include "Game.h"

#include <raylib.h>

Game::Game() : w_width(1280), w_height(960), current_state(GameState::MENU) {}

Game::Game(int window_width, int window_height)
    : w_width(window_width), w_height(window_height),
      current_state(GameState::MENU)
{
    InitWindow(w_width, w_height, "PONG 2026");
}

void Game::run()
{
    init();
    while (!WindowShouldClose())
    {
        update();
        draw();
    }
    CloseWindow();
}

void Game::init() {}

void Game::update() {}

void Game::draw() {}
