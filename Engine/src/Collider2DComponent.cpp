#include <SDL3/SDL.h>
#include "Collider2DComponent.hpp"
#include "GameEntity.hpp"

Collider2DComponent::Collider2DComponent() {

}

Collider2DComponent::~Collider2DComponent() {
}

void Collider2DComponent::Update(float deltaTime) {
    auto transform = getGameEntity()->GetTransform();
    SetWH(transform->GetW(), transform->GetH());
    SetXY(transform->GetX(), transform->GetY());
}

ComponentType Collider2DComponent::GetType() {
    return ComponentType::Collider2DComponent;
}

void Collider2DComponent::SetW(float w) {
    mRectangle.w = w;
}

void Collider2DComponent::SetH(float h) {
    mRectangle.h = h;
}

void Collider2DComponent::SetWH(float w, float h) {
    mRectangle.w = w;
    mRectangle.h = h;
}

float Collider2DComponent::GetW() const {
    return mRectangle.w;
}

float Collider2DComponent::GetH() const {
    return mRectangle.h;
}

void Collider2DComponent::SetX(float x) {
    mRectangle.x = x;
}

void Collider2DComponent::SetY(float y) {
    mRectangle.y = y;
}

void Collider2DComponent::SetXY(float x, float y) {
    mRectangle.x = x;
    mRectangle.y = y;
}

const float Collider2DComponent::GetX() {
    return mRectangle.x;
}

const float Collider2DComponent::GetY() {
    return mRectangle.y;
}

SDL_FRect Collider2DComponent::GetRectangle() const {
    return mRectangle;
}
