#include "InputComponent.hpp"
#include "GameEntity.hpp"

InputComponent::InputComponent() {

}

InputComponent::~InputComponent() {

}

void InputComponent::Input(float deltaTime) {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    auto ge = getGameEntity();
    auto transform = ge->GetComponent<TransformComponent>(ComponentType::TransformComponent);
    transform->SetAngle(0.0);
    if (state[SDL_SCANCODE_LEFT]) {
        transform->SetX(transform->GetX() - mSpeed * deltaTime);
        transform->SetAngle(-90.0f);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        transform->SetX(transform->GetX() + mSpeed * deltaTime);
        transform->SetAngle(90);
    }
    if (state[SDL_SCANCODE_UP]) {
        transform->SetY(transform->GetY() - mSpeed * deltaTime);
        if(transform->GetAngle() > 0) {
            transform->SetAngle(transform->GetAngle() - 45);
        } else if(transform->GetAngle() < 0) {
            transform->SetAngle(transform->GetAngle() + 45);
        }
    }
    if (state[SDL_SCANCODE_DOWN]) {
        transform->SetY(transform->GetY() + mSpeed * deltaTime);
        if(transform->GetAngle() > 0) {
            transform->SetAngle(transform->GetAngle() + 45);
        } else if(transform->GetAngle() < 0) {
            transform->SetAngle(transform->GetAngle() - 45);
        } else {
            transform->SetAngle(180.0);
        }
    }
}

ComponentType InputComponent::GetType() {
    return ComponentType::InputComponent;
}
