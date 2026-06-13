#pragma once

#include "InputController.hpp"

#include <raylib.h>

class Paddle
{
private:
    Vector2 size;
    Vector2 position;
    Vector2 speed;
    InputController* controller;

public:
    Paddle();
    void Update();
    void Draw();
    Rectangle GetRect();
    void SetController(InputController* controller);

    Vector2 getPosition() const;
    void setPosition(Vector2 position);
    Vector2 getSize() const;
};
