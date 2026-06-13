#pragma once

#include "Ball.hpp"
#include "InputController.hpp"
#include "Paddle.hpp"

class AIController : public InputController
{
private:
    Ball* ball;
    Paddle* paddle;

public:
    AIController(Ball* ball, Paddle* paddle);
    float getDirection() override;
};
