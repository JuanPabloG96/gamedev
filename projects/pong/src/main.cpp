#include <raylib.h>

enum class GameState
{
    MENU,
    PVE,
    PVP,
    GAMEOVER
};

struct Ball
{
    float radius = 8.0f;
    Vector2 position = {0, 0};
    Vector2 speed = {900, 450};
    Color color = WHITE;

    void Update()
    {
        position.x += speed.x * GetFrameTime();
        position.y += speed.y * GetFrameTime();

        if (position.y + radius >= GetScreenHeight() ||
            position.y - radius <= 0)
            speed.y *= -1;
    }

    void reset()
    {
        position = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
        speed.x *= -1;
        if (speed.x > 0)
            speed = {900, 450};
        else
            speed = {-900, 450};
    }

    void Draw() { DrawCircleV(position, radius, color); }
};

struct Paddle
{
    Vector2 position = {0, 0};
    Vector2 size = {8, 100};
    float speed = 1000;
    Color color = WHITE;
    unsigned int score = 0;

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

int GetPlayerInput()
{
    if (IsKeyDown(KEY_W))
        return -1;
    else if (IsKeyDown(KEY_S))
        return 1;
    return 0;
}

float GetNPCInput(const Ball& ball, const Paddle& npc)
{
    float paddleCenterY = npc.position.y + (npc.size.y / 2.0f);
    float threshold = 40.0f;

    if (ball.position.y < paddleCenterY - threshold)
        return -1.0f;
    else if (ball.position.y > paddleCenterY + threshold)
        return 1.0f;
    return 0.0f;
}

void CheckGameOver(const Paddle& p1, const Paddle& p2)
{
    if (p1.score >= 5 || p2.score >= 5)
    {
        DrawText("Game Over",
                 GetScreenWidth() / 2 - (MeasureText("Game Over", 120) / 2),
                 GetScreenHeight() / 2,
                 120,
                 WHITE);
    }
}

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

    while (!WindowShouldClose())
    {
        float p_direction = GetPlayerInput();
        float npc_direction = GetNPCInput(ball, paddel_right);

        ball.Update();
        paddel_left.Update(p_direction);
        paddel_right.Update(npc_direction);

        if (ball.position.x < 0)
        {
            paddel_right.score++;
            ball.reset();
        }
        if (ball.position.x > GetScreenWidth())
        {
            paddel_left.score++;
            ball.reset();
        }

        if (CheckCollisionCircleRec(
                ball.position, ball.radius, paddel_left.GetRect()))
        {
            ball.speed.x *= -1;
            if (p_direction != 0)
            {
                ball.speed.y += 50 * p_direction;
            }
            ball.position.x =
                paddel_left.position.x + paddel_left.size.x + ball.radius;
        }
        if (CheckCollisionCircleRec(
                ball.position, ball.radius, paddel_right.GetRect()))
        {
            ball.speed.x *= -1;
            if (npc_direction != 0)
            {
                ball.speed.y += 50 * npc_direction;
            }
            ball.position.x = paddel_right.position.x - ball.radius;
        }

        BeginDrawing();

        ClearBackground(BLACK);
        ball.Draw();
        paddel_left.Draw();
        paddel_right.Draw();

        DrawText(TextFormat("%i", paddel_left.score), 200, 80, 180.0f, WHITE);
        DrawText(TextFormat("%i", paddel_right.score),
                 GetScreenWidth() - 200,
                 80,
                 180.0f,
                 WHITE);
        CheckGameOver(paddel_left, paddel_right);

        for (int i = 0; i < GetScreenHeight(); i += 60)
        {
            DrawLineEx({(float)GetScreenWidth() / 2, (float)i},
                       {(float)GetScreenWidth() / 2, (float)(i + 40)},
                       8.0f,
                       WHITE);
        }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
