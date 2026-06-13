#pragma once

class InputController
{
public:
    virtual float getDirection() = 0;
    virtual ~InputController() = default;
};
