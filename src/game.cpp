//
// Created by Enger Jiménez on 19/2/26.
//
#include <iostream>
#include <string>

#include "raylib.h"

#include "ball.h"
#include "constants.h"
#include "game.h"
#include "paddle.h"

Game::Game()
    : m_score({{"player", 0}, {"cpu", 0}})
      , m_ball(Vector2{HALF_WIDTH, HALF_HEIGHT})
      , m_cpuPaddle(CpuPaddle(m_ball))
      , m_playerPaddle(Paddle()) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "[Rey Pong] - by Enger Jiménez");
    SetTargetFPS(120);
    SetExitKey(0);
}

Game::~Game() {
    std::cout << "[GAME] Exiting Game" << std::endl;
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        const float delta = GetFrameTime();

        // =================
        // Check score
        // =================
        if (m_ball.m_position.x + Ball::RADIUS >= SCREEN_WIDTH) {
            m_score["player"] += 1;
            m_ball.reset();
        }

        if (m_ball.m_position.x - Ball::RADIUS <= 0) {
            m_score["cpu"] += 1;
            m_ball.reset();
        }

        bounceBall();

        update(delta);
        draw();
    }
}

void Game::update(const float delta) {
    m_ball.update(delta);
    m_cpuPaddle.update(delta);
    m_playerPaddle.update(delta);
}

void Game::draw() const {
    BeginDrawing();
    ClearBackground(DARKGRAY);
    DrawFPS(SCREEN_WIDTH - 80, 10);

    // =================
    // Draw Score
    // =================
    const auto playerScore = "Player Score: " + std::to_string(m_score.at("player"));
    const auto cpuScore = "CPU Score: " + std::to_string(m_score.at("cpu"));

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
        Ball::RADIUS * 6, // Court circle radius
        RAYWHITE
    );

    // =================
    // Draw Entities
    // =================
    m_ball.draw();
    m_cpuPaddle.draw();
    m_playerPaddle.draw();

    EndDrawing();
}

void Game::bounceBall() {
    // TODO: Refactor this method to avoid code duplication.
    // It is possible to have a list of collidable entities and check for collisions in a loop.

    const auto collidedWithCpu = Ball::collided(
        m_ball,
        Rectangle{
            m_cpuPaddle.m_position.x,
            m_cpuPaddle.m_position.y,
            m_cpuPaddle.m_size.x,
            m_cpuPaddle.m_size.y,
        });
    const auto collidedWithPlayer = Ball::collided(
        m_ball,
        Rectangle{
            m_playerPaddle.m_position.x,
            m_playerPaddle.m_position.y,
            m_playerPaddle.m_size.x,
            m_playerPaddle.m_size.y,
        });

    if (collidedWithCpu || collidedWithPlayer) {
        m_ball.m_velocity.x *= -1;
    }
}
