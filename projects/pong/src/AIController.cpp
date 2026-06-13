#include "AIController.hpp"

AIController::AIController(Ball* ball, Paddle* paddle)
    : ball(ball), paddle(paddle)
{
}

float AIController::getDirection()
{
    float center = paddle->getPosition().y + paddle->getSize().y / 2;

    if (ball->getPosition().y < center - 30)
        return -1.0f;

    if (ball->getPosition().y > center + 30)
        return 1.0f;

    return 0.0f;
}
