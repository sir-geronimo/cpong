//
// Created by Enger Jiménez on 19/2/26.
//
#include "raylib.h"
#include "raymath.h"

#include "paddle.h"
#include "constants.h"

Paddle::Paddle()
    : m_position(Vector2{ .y = HALF_HEIGHT - PADDLE_SIZE_Y / 2.0f})
      , m_velocity(Vector2())
      , m_size(Vector2{PADDLE_SIZE_X, PADDLE_SIZE_Y}) {
}

Paddle::Paddle(const Vector2 &position) : m_position(position) {
}

void Paddle::move(const float delta) {
    // Apply velocity to position
    m_position = Vector2Add(m_position, Vector2Scale(m_velocity, delta));

    // Clamp position to stay within screen bounds
    if (m_position.y <= 0) {
        m_position.y = 0;
    }
    if (m_position.y + m_size.y >= SCREEN_HEIGHT) {
        m_position.y = SCREEN_HEIGHT - m_size.y;
    }
}

void Paddle::update(const float delta) {
    if (IsKeyDown(KEY_S)) {
        m_velocity.y = Clamp(m_velocity.y + SPEED, -MAX_SPEED, MAX_SPEED);
    } else if (IsKeyDown(KEY_W)) {
        m_velocity.y = Clamp(m_velocity.y - SPEED, -MAX_SPEED, MAX_SPEED);
    } else {
        m_velocity.y *= 0.3f; // fixed max vertical speed
    }

    move(delta);
}

void Paddle::draw() const {
    DrawRectangleRounded(
        Rectangle(m_position.x, m_position.y, m_size.x, m_size.y),
        1,
        10,
        RAYWHITE);
}
