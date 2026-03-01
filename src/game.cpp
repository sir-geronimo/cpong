//
// Created by Enger Jiménez on 19/2/26.
//
#include <string>

#include "raylib.h"

#include "ball.h"
#include "constants.h"
#include "game.h"
#include "paddle.h"

Game::Game()
    : score({{"player", 0}, {"cpu", 0}})
      , ball(Vector2{HALF_WIDTH, HALF_HEIGHT})
      , cpuPaddle(CpuPaddle())
      , playerPaddle(Paddle()) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rey Pong");
    SetTargetFPS(120);
    SetExitKey(0);
}

Game::~Game() {
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        const float delta = GetFrameTime();

        // =================
        // Check score
        // =================
        if (ball.position.x + Ball::RADIUS >= SCREEN_WIDTH) {
            score["player"] += 1;
            ball.reset();
        }

        if (ball.position.x - Ball::RADIUS <= 0) {
            score["cpu"] += 1;
            ball.reset();
        }

        bounceBall();

        update(delta);
        draw();
    }
}

void Game::update(const float delta) {
    ball.update(delta);
    cpuPaddle.update(delta, ball);
    playerPaddle.update(delta);
}

void Game::draw() const {
    BeginDrawing();
    ClearBackground(DARKGRAY);
    DrawFPS(SCREEN_WIDTH - 80, 10);

    // =================
    // Draw Score
    // =================
    const auto playerScore = "Player Score: " + std::to_string(score.at("player"));
    const auto cpuScore = "CPU Score: " + std::to_string(score.at("cpu"));

    DrawText(
        playerScore.c_str(),
        20, 10, 16, RAYWHITE
    );
    DrawText(
        cpuScore.c_str(),
        20, 40, 16, RAYWHITE
    );

    // =================
    // Draw Court
    // =================
    DrawLineV(
        Vector2{HALF_WIDTH, 0},
        Vector2{HALF_WIDTH, SCREEN_HEIGHT},
        RAYWHITE
    );
    DrawCircleLinesV(
        Vector2{HALF_WIDTH, HALF_HEIGHT},
        60,
        RAYWHITE
    );

    // =================
    // Draw Entities
    // =================
    ball.draw();
    cpuPaddle.draw();
    playerPaddle.draw();

    EndDrawing();
}

void Game::bounceBall() {
    if (Ball::collided(
        ball,
        Rectangle{
            cpuPaddle.position.x, cpuPaddle.position.y,
            cpuPaddle.size.x, cpuPaddle.size.y
        }
    )) {
        ball.m_velocity.x *= -1;
    }

    if (Ball::collided(
        ball,
        Rectangle{
            playerPaddle.position.x, playerPaddle.position.y,
            playerPaddle.size.x, playerPaddle.size.y
        }
    )) {
        ball.m_velocity.x *= -1;
    }
}
