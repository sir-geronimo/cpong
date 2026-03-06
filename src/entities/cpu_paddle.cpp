//
// Created by Enger Jiménez on 28/2/26.
//
#include "raylib.h"
#include "raymath.h"

#include "ball.h"
#include "paddle.h"
#include "constants.h"

CpuPaddle::CpuPaddle(const Ball &ball)
    : Paddle(Vector2{
          .x = SCREEN_WIDTH - PADDLE_SIZE_X,
          .y = HALF_HEIGHT - PADDLE_SIZE_Y / 2.0f
      })
      , m_ball(ball) {
}

CpuPaddle::CpuPaddle(const Ball &ball, const Vector2 &position)
    : Paddle(position)
      , m_ball(ball) {
}

void CpuPaddle::update(const float delta) {
    calculateBallPos();
    move(delta);
}

void CpuPaddle::calculateBallPos() {
    const bool isBallComing = m_ball.m_position.x >= HALF_WIDTH;

    // Only react if the ball is on this side and moving toward the paddle
    if (const bool ballComing = m_ball.m_velocity.x > 0; isBallComing && ballComing) {
        const float centerY = m_position.y + m_size.y / 2.0f;
        const float targetY = m_ball.m_position.y;
        const float direction = targetY > centerY ? 1.0f : -1.0f;

        m_velocity.y = Clamp(m_velocity.y + SPEED * direction, -MAX_SPEED, MAX_SPEED);
    } else {
        m_velocity.y *= 0.5f;
    }
}
