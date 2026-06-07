#include <raylib.h>

struct Ball
{
    float radius = 8.0f;
    Vector2 position = {(float)GetScreenWidth() / 2,
                        (float)GetScreenHeight() / 2};
    Vector2 speed = {500, 500};
    Color color = WHITE;

    void Update()
    {
        // Movement
        position.x += speed.x * GetFrameTime();
        position.y += speed.y * GetFrameTime();

        // Screen vertical limits collision
        if (position.y + radius >= GetScreenHeight() ||
            position.y - radius <= 0)
            speed.y *= -1;

        reset();
    }

    void reset()
    {
        if (position.x - (2 * radius) > GetScreenWidth() ||
            position.x + (2 * radius) < 0)
        {
            position = {(float)GetScreenWidth() / 2,
                        (float)GetScreenHeight() / 2};

            speed.x *= -1;
        }
    }

    void Draw() { DrawCircleV(position, radius, color); }
};

struct Paddle
{
    Vector2 position = {(float)GetScreenWidth() / 2,
                        (float)GetScreenHeight() / 2};
    Vector2 size = {8, 60};
    float speed = 600;
    Color color = WHITE;

    Rectangle GetRect() const
    {
        return {position.x, position.y, size.x, size.y};
    }

    void Update(float direction)
    {
        if (position.y < 0 && direction == -1)
            return;
        if (position.y > GetScreenHeight() - size.y && direction == 1)
            return;
        position.y += direction * speed * GetFrameTime();
    }

    void Draw() const { DrawRectangleV(position, size, color); }
};

struct Wall
{
    Vector2 position;
    Vector2 size;
    Color color;

    void Draw() const { DrawRectangleV(position, size, color); }
};

int main()
{
    const int w_width = 1280;
    const int w_height = 960;
    const int target_fps = 60;

    InitWindow(w_width, w_height, "Mi Primer Pong en C++");

    SetTargetFPS(target_fps);

    // Ball
    Ball ball;
    ball.position = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};

    // Padel left
    Paddle paddel_left;
    paddel_left.position = {50.0f, (float)GetScreenHeight() / 2};

    // Padel right
    Paddle paddel_right;
    paddel_right.position = {GetScreenWidth() - 50.0f,
                             (float)GetScreenHeight() / 2};

    float direction = 0;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_W))
            direction = -1;
        else if (IsKeyDown(KEY_S))
            direction = 1;
        else
            direction = 0;

        ball.Update();
        paddel_left.Update(direction);

        BeginDrawing();

        ClearBackground(BLACK);
        ball.Draw();
        paddel_left.Draw();
        paddel_right.Draw();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
