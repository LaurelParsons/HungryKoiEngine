#include "GameEntity.hpp"
#include "InputComponent.hpp"
#include "Collider2DComponent.hpp"


GameEntity::GameEntity() {
}
GameEntity::~GameEntity() {

}
void GameEntity::Input(float deltaTime) {
    for (auto& [key, value] : mComponents) {
        mComponents[key]->Input(deltaTime);
    }

    for (auto& children : mGameEntities) {
        children->Input(deltaTime);
    }
}
void GameEntity::Update(float deltaTime) {
    for (auto& [key, value] : mComponents) {
        mComponents[key]->Update(deltaTime);
    }
    for (auto& children : mGameEntities) {
        children->Update(deltaTime);
    }
}

void GameEntity::Render(SDL_Renderer* renderer) {
    for (auto& [key, value] : mComponents) {
        mComponents[key]->Render(renderer);
    }
    for (auto& children : mGameEntities) {
        children->Render(renderer);
    }
}

template<typename T>
void GameEntity::AddComponent(std::shared_ptr<T> component) {
    mComponents[component->GetType()] = component;
    component->SetGameEntity(GetThisPtr());
}

template<typename T>
std::shared_ptr<T> GameEntity::GetComponent(ComponentType type) {
    auto found = mComponents.find(type);
    if (found != mComponents.end()) {
        return std::dynamic_pointer_cast<T>(found->second);
    }
    SDL_Log("ERROR: The component you searched for was not found");
    return nullptr;
}

void GameEntity::AddDefaultTransform() {
    std::shared_ptr<TransformComponent> t = std::make_shared<TransformComponent>();
    AddComponent<TransformComponent>(t);
}

std::shared_ptr<TransformComponent> GameEntity::GetTransform() {
    return GetComponent<TransformComponent>(ComponentType::TransformComponent);
}

void GameEntity::AddChildGameEntity(std::shared_ptr<GameEntity> child) {
    mGameEntities.push_back(child);
}

std::shared_ptr<GameEntity> GameEntity::GetChildGameEntityAtIndex(size_t index) {
    return mGameEntities.at(index);
}

void GameEntity::setRenderable(bool renderable) {
    mRenderable = renderable;
}

bool GameEntity::IsRenderable() const {
    return mRenderable;
}

bool GameEntity::Intersects(std::shared_ptr<GameEntity> e) {
    auto source = e->GetComponent<Collider2DComponent>(ComponentType::Collider2DComponent)->GetRectangle();
    auto us = GetComponent<Collider2DComponent>(ComponentType::Collider2DComponent)->GetRectangle();

    SDL_FRect result;
    return SDL_GetRectIntersectionFloat(&source, &us, &result);
}

void GameEntity::SetScore(int newScore) {
    score = newScore;
}

int GameEntity::GetScore() {
    return score;
}

//Explicit template instantiationsS
template void GameEntity::AddComponent<TextureComponent>(std::shared_ptr<TextureComponent> C);
template std::shared_ptr<TextureComponent> GameEntity::GetComponent<TextureComponent>(ComponentType type);

template void GameEntity::AddComponent<Collider2DComponent>(std::shared_ptr<Collider2DComponent> C);
template std::shared_ptr<Collider2DComponent> GameEntity::GetComponent<Collider2DComponent>(ComponentType type);

template void GameEntity::AddComponent<TransformComponent>(std::shared_ptr<TransformComponent> C);
template std::shared_ptr<TransformComponent> GameEntity::GetComponent<TransformComponent>(ComponentType type);

template void GameEntity::AddComponent<InputComponent>(std::shared_ptr<InputComponent> C);
template std::shared_ptr<InputComponent> GameEntity::GetComponent<InputComponent>(ComponentType type);
