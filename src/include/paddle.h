//
// Created by Enger Jiménez on 19/2/26.
//
// Created by Enger Jiménez on 19/2/26.
//
#pragma once

#include "raylib.h"

#include "ball.h"
#include "constants.h"
#include "object.h"

class Ball;

class Paddle : public Object {
protected:
    static constexpr float SPEED = 100.0f;
    static constexpr float MAX_SPEED = 200.0f;
    static constexpr float ACCELERATION = 800;

    void move(float delta);

public:
    ~Paddle() override = default;

    Vector2 m_position{};
    Vector2 m_velocity{};
    Vector2 m_size{PADDLE_SIZE_X, PADDLE_SIZE_Y};

    explicit Paddle();

    explicit Paddle(const Vector2 &position);

    void update(float delta) override;

    void draw() const override;
};

class CpuPaddle : public Paddle {
    const Ball &m_ball;

public:
    explicit CpuPaddle(const Ball &ball);

    explicit CpuPaddle(const Ball &ball, const Vector2 &position);

    void update(float delta) override;

private:
    void calculateBallPos();
};
