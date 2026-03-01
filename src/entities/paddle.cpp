//
// Created by Enger Jiménez on 19/2/26.
//
#include "raylib.h"
#include "raymath.h"

#include "paddle.h"
#include "constants.h"

Paddle::Paddle()
    : position(Vector2{.x = 0, .y = HALF_HEIGHT - PADDLE_SIZE_Y / 2.0f})
      , velocity(Vector2{0, 0})
      , size(Vector2{PADDLE_SIZE_X, PADDLE_SIZE_Y}) {
}

Paddle::Paddle(const Vector2 &position) : position(position) {
}

void Paddle::move(const float delta) {
    // Apply velocity to position
    position = Vector2Add(position, Vector2Scale(velocity, delta));

    // Clamp position to stay within screen bounds
    if (position.y <= 0) {
        position.y = 0;
    }
    if (position.y + size.y >= SCREEN_HEIGHT) {
        position.y = SCREEN_HEIGHT - size.y;
    }
}

void Paddle::update(const float delta) {
    if (IsKeyDown(KEY_S)) {
        velocity.y = Clamp(velocity.y + SPEED, -MAX_SPEED, MAX_SPEED);
    } else if (IsKeyDown(KEY_W)) {
        velocity.y = Clamp(velocity.y - SPEED, -MAX_SPEED, MAX_SPEED);
    } else {
        velocity.y *= 0.3f;
    }

    move(delta);
}

void Paddle::draw() const {
    DrawRectangleRounded(
        Rectangle{position.x, position.y, size.x, size.y},
        1,
        10,
        RAYWHITE);
}
