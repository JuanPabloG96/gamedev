#pragma once

#include "raylib.h"

class Ball
{
private:
    int radius;
    Vector2 position;
    Vector2 speed;
    void reset();

public:
    Ball();
    void update();
    void draw();
    Vector2 getPosition() const;
    void setPosition();
};
