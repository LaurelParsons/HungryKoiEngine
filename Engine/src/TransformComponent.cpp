#include <SDL3/SDL.h>
#include <iostream>
#include <math.h>

#include "TransformComponent.hpp"
#include "GameEntity.hpp"
#include "Vector2.hpp"

TransformComponent::TransformComponent() {
    mRectangle = { 20.0f,20.0f,startingW,startingH };
}

TransformComponent::~TransformComponent() {
}

void TransformComponent::Update(float deltaTime) {
    auto ge = getGameEntity();
    SetWH(float(startingW + ge->GetScore()), float(startingH + ge->GetScore()));
}

ComponentType TransformComponent::GetType() {
    return ComponentType::TransformComponent;
}

void TransformComponent::SetW(float w) {
    mRectangle.w = w;
}

void TransformComponent::SetH(float h) {
    mRectangle.h = h;
}

void TransformComponent::SetWH(float w, float h) {
    mRectangle.w = w;
    mRectangle.h = h;
}

float TransformComponent::GetW() const {
    return mRectangle.w;
}

float TransformComponent::GetH() const {
    return mRectangle.h;
}

void TransformComponent::SetX(float x) {
    mRectangle.x = x;
}

void TransformComponent::SetY(float y) {
    mRectangle.y = y;
}

void TransformComponent::SetXY(Vector2 position) {
    mRectangle.x = position.x;
    mRectangle.y = position.y;
}

const float TransformComponent::GetX() {
    return mRectangle.x;
}

const float TransformComponent::GetY() {
    return mRectangle.y;
}

const float TransformComponent::GetAngle() {
    return angle;
}

void TransformComponent::SetAngle(float angle) {
    this->angle = angle;
}

const Vector2 TransformComponent::GetPosition() {
    return Vector2(mRectangle.x, mRectangle.y);
}

SDL_FRect TransformComponent::GetRectangle() const {
    return mRectangle;
}
