//
// Created by Enger Jiménez on 19/2/26.
//
// Created by Enger Jiménez on 19/2/26.
//
#pragma once

#include "raylib.h"

#include "constants.h"

class Ball;

class Paddle {
protected:
    static constexpr float SPEED = 100.0f;
    static constexpr float MAX_SPEED = 200.0f;
    static constexpr float ACCELERATION = 800;

    void move(float delta);

public:
    virtual ~Paddle() = default;

    Vector2 position{};
    Vector2 velocity{};
    Vector2 size{PADDLE_SIZE_X, PADDLE_SIZE_Y};

    explicit Paddle();

    explicit Paddle(const Vector2 &position);

    virtual void update(float delta);

    void draw() const;
};

class CpuPaddle : public Paddle {
public:
    explicit CpuPaddle();

    explicit CpuPaddle(const Vector2 &position);

    void update(float delta, const Ball &ball);

private:
    void calculateBallPos(const Ball &ball);
};
