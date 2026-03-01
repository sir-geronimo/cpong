//
// Created by Enger Jiménez on 24/4/25.
//
#include "raylib.h"
#include "raymath.h"

#include "ball.h"
#include "constants.h"

Ball::Ball(const Vector2 &initialPos)
    : initialPosition(initialPos)
      , position(initialPos) {
    reset();
}

void Ball::update(const float delta) {
    if (position.y - RADIUS <= 0 || position.y + RADIUS >= SCREEN_HEIGHT) {
        m_velocity.y *= -1;
    }

    position.x += m_velocity.x * delta;
    position.y += m_velocity.y * delta;
}

void Ball::draw() const {
    DrawCircleV(position, RADIUS, RAYWHITE);
}

void Ball::reset() {
    // Restart position to initial position
    position = initialPosition;

    // Set a random angle between -45 and 45 degrees
    auto angle = static_cast<float>(GetRandomValue(-45, 45));

    // Choose a side (Left or Right)
    if (GetRandomValue(0, 1) == 0) {
        angle += 180.0f;
    }

    m_velocity = Vector2Rotate(Vector2{SPEED, 0}, angle * DEG2RAD);
}

bool Ball::collided(const Ball &ball, const Rectangle &rec) {
    if (rec.x > ball.position.x + 100 || rec.x < ball.position.x - 100) {
        return false;
    }

    return CheckCollisionCircleRec(
        ball.position,
        RADIUS,
        rec
    );
}
