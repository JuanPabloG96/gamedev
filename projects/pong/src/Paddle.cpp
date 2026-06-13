#include "Paddle.hpp"

#include "raylib.h"

void Paddle::Update() {}

void Paddle::Draw() { DrawRectangleV(position, size, WHITE); }

Rectangle Paddle::GetRect() { return {position.x, position.y, size.x, size.y}; }

void Paddle::SetController(InputController* controller)
{
    this->controller = controller;
}

Vector2 Paddle::getPosition() const { return this->position; }

void Paddle::setPosition(Vector2 position) { this->position = position; }

Vector2 Paddle::getSize() const { return this->size; }
