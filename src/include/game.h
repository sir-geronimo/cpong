//
// Created by Enger Jiménez on 19/2/26.
//
#pragma once

#include <unordered_map>

#include "ball.h"
#include "paddle.h"

class Game {
    std::unordered_map<std::string, int> m_score;
    Ball m_ball;
    CpuPaddle m_cpuPaddle;
    Paddle m_playerPaddle;

public:
    explicit Game();

    ~Game();

    void Run();

private:
    void update(float delta);

    void draw() const;

    void bounceBall();
};
