#include "Game.hpp"

#include <iostream>
#include <raylib.h>

Game::Game() : Game(1280, 960) {}

Game::Game(int window_width, int window_height)
    : w_width(window_width), w_height(window_height),
      current_state(GameState::MENU)
{
    InitWindow(w_width, w_height, "PONG 2026");
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        init();
        update();
        draw();
    }
    CloseWindow();
}

void Game::init()
{
    switch (current_state)
    {
        case GameState::MENU:
            break;
        case GameState::PVE:
            break;
        case GameState::PVP:
            break;
        case GameState::GAME_OVER:
            break;
        default:
            std::cerr << "Error setting game state" << std::endl;
    }
}

void Game::update()
{
    switch (current_state)
    {
        case GameState::MENU:
            break;
        case GameState::PVE:
            break;
        case GameState::PVP:
            break;
        case GameState::GAME_OVER:
            break;
        default:
            std::cerr << "Error setting game state" << std::endl;
    }
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    switch (current_state)
    {
        case GameState::MENU:
            break;
        case GameState::PVE:
            break;
        case GameState::PVP:
            break;
        case GameState::GAME_OVER:
            break;
        default:
            std::cerr << "Error setting game state" << std::endl;
    }

    EndDrawing();
}
