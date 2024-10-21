#include <SDL3/SDL.h>

#include "ResourceManager.hpp"
#include "TextureComponent.hpp"
#include "GameEntity.hpp"

TextureComponent::TextureComponent() {

}

void TextureComponent::CreateSprite(SDL_Renderer* renderer, std::string filepath) {
    mTexture = ResourceManager::Instance().LoadTexture(renderer, filepath);
}
TextureComponent::~TextureComponent() {

}

void TextureComponent::Render(SDL_Renderer* renderer) {
    auto ge = getGameEntity();
    auto rect = ge->GetTransform()->GetRectangle();
    float angle = ge->GetTransform()->GetAngle();
    if (nullptr == mTexture) {
        SDL_RenderRect(renderer, &rect);
    }
    else {
        SDL_RenderTextureRotated(renderer, mTexture.get(), nullptr, &rect, angle, nullptr, SDL_FLIP_NONE);
    }
}

ComponentType TextureComponent::GetType() {
    return ComponentType::TextureComponent;
}
