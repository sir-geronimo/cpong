//
// Created by Enger Jiménez on 24/4/25.
//
#include "raylib.h"
#include "raymath.h"

#include "ball.h"
#include "constants.h"

Ball::Ball(const Vector2 &initialPos)
    : m_initialPosition(initialPos)
      , m_position(initialPos) {
    reset();
}

void Ball::update(const float delta) {
    if (m_position.y - RADIUS <= 0 || m_position.y + RADIUS >= SCREEN_HEIGHT) {
        m_velocity.y *= -1;
    }

    m_position.x += m_velocity.x * delta;
    m_position.y += m_velocity.y * delta;
}

void Ball::draw() const {
    DrawCircleV(m_position, RADIUS, RAYWHITE);
}

void Ball::reset() {
    // Restart position to initial position
    m_position = m_initialPosition;

    // Set a random angle between -45 and 45 degrees
    auto angle = static_cast<float>(GetRandomValue(-45, 45));

    // Choose a side (Left or Right)
    if (GetRandomValue(0, 1) == 0) {
        angle += 180.0f;
    }

    m_velocity = Vector2Rotate(Vector2{SPEED, 0}, angle * DEG2RAD);
}

bool Ball::collided(const Ball &ball, const Rectangle &rec) {
    if (rec.x > ball.m_position.x + 100 || rec.x < ball.m_position.x - 100) {
        return false;
    }

    return CheckCollisionCircleRec(
        ball.m_position,
        RADIUS,
        rec
    );
}
