//
// Created by Enger Jiménez on 19/02/2026
//
#pragma once

#include "raylib.h"

#include "object.h"

class Ball : public Object {
public:
    static constexpr float RADIUS = 10.0f;
    static constexpr float SPEED = 200.0f;

    Vector2 m_initialPosition{};
    Vector2 m_position{};
    Vector2 m_velocity{SPEED, SPEED};

    explicit Ball(const Vector2 &initialPos);

    void update(float delta) override;

    void draw() const override;

    void reset();

    static bool collided(const Ball &ball, const Rectangle &rec);
};
