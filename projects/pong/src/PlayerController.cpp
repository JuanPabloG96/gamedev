#include "PlayerController.hpp"

PlayerController::PlayerController(KeyboardKey up, KeyboardKey down)
    : up(up), down(down)
{
}

float PlayerController::getDirection()
{
    if (IsKeyDown(up))
        return -1;
    else if (IsKeyDown(down))
        return 1;
    return 0;
}
