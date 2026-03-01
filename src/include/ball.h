//
// Created by Enger Jiménez on 19/02/2026
//
#pragma once

#include "raylib.h"

class Ball {
public:
    static constexpr float RADIUS = 10.0f;
    static constexpr float SPEED = 200.0f;

    Vector2 initialPosition{};
    Vector2 position{};
    Vector2 m_velocity{SPEED, SPEED};

    explicit Ball(const Vector2 &initialPos);

    void update(float delta);

    void draw() const;

    void reset();

    static bool collided(const Ball &ball, const Rectangle &rec);
};
