//
// Created by Enger Jiménez on 28/2/26.
//
#include "raylib.h"
#include "raymath.h"

#include "ball.h"
#include "paddle.h"
#include "constants.h"

CpuPaddle::CpuPaddle() : Paddle(
    Vector2{
        .x = SCREEN_WIDTH - PADDLE_SIZE_X,
        .y = HALF_HEIGHT - PADDLE_SIZE_Y / 2.0f
    }
) {
}

CpuPaddle::CpuPaddle(const Vector2 &position) : Paddle(position) {
}

void CpuPaddle::update(const float delta, const Ball &ball) {
    calculateBallPos(ball);
    move(delta);
}

void CpuPaddle::calculateBallPos(const Ball &ball) {
    const bool isBallComing = ball.position.x >= HALF_WIDTH;

    // Only react if the ball is on this side and moving toward the paddle
    if (const bool ballComing = ball.m_velocity.x > 0; isBallComing && ballComing) {
        const float centerY = position.y + size.y / 2.0f;
        const float targetY = ball.position.y;
        const float direction = targetY > centerY ? 1.0f : -1.0f;

        velocity.y = Clamp(velocity.y + SPEED * direction, -MAX_SPEED, MAX_SPEED);
    } else {
        velocity.y *= 0.5f;
    }
}
