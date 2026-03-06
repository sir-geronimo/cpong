//
// Created by Enger Jiménez on 5/3/26.
//
#pragma once
class Object {
public:
    virtual ~Object() = default;

    virtual void update(float delta) = 0;
    virtual void draw() const = 0;
};
