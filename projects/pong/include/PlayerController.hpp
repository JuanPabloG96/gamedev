#pragma once

#include "InputController.hpp"
#include "raylib.h"

class PlayerController : public InputController
{
private:
    KeyboardKey up;
    KeyboardKey down;

public:
    PlayerController(KeyboardKey up, KeyboardKey down);
    float getDirection() override;
};
