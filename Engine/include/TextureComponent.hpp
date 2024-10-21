#pragma once
#include <memory>
#include <string>
#include <SDL3/SDL.h>

#include "Component.hpp"

/**
* Component that holds the texture to be rendered for a game entity.
*
* The TextureComponent contains a SDL_Texture object holding the image to be rendered onto a game entity.
*/
struct TextureComponent : public Component {

    /**
    Creates a new texture component.
    */
    TextureComponent();

    /**
    Creates a sprite from the given filepath.

    Creates a SDL_Texture object from the image stored at the given filepath, using the given renderer.

    \param renderer SDL_Renderer to use to draw the sprite
    \param filepath The path to the image to use as a sprite
    */
    void CreateSprite(SDL_Renderer* renderer, std::string filepath);

    /**
    Destroys this texture component.
    */
    ~TextureComponent();

    /**
    Renders the texture.

    Renders the sprite texture in the scene based on the location, size, and angle stored in the game entity's transform.

    \param renderer SDL_Renderer used to draw the texture
    */
    void Render(SDL_Renderer* renderer) override;

    /**
    Returns ComponentType.TextureComponent
    */
    ComponentType GetType() override;

private:
    /**
    The sprite texture.
    */
    std::shared_ptr<SDL_Texture> mTexture;
};
