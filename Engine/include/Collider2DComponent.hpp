#pragma once
#include <memory>
#include <string>
#include <SDL3/SDL.h>

#include "Component.hpp"

/**
* A component containing the 2D collider for a game object.
*
* This class is a component type that holds the collider for a game object.
* A collider is represented by a SDL_rect of the space the game object takes up.
* Can detect if a collider intersects with another collider.
*/
struct Collider2DComponent : public Component {

    /**
    Creates a new Collider component.
    */
    Collider2DComponent();

    /**
    Destroy this collider component.
    */
    ~Collider2DComponent();

    /**
    Update collider position.

    Checks the game entity's transform component to get updated position,
    then sets the location of the collider rect to match.

    \param deltaTime Time since update was last called
    */
    void Update(float deltaTime) override;

    /**
    Returns the type of this component.

    Returns ComponentType.Collider2DComponent
    */
    ComponentType GetType() override;

    /**
    Set the width of this collider rect.
    \param w Width
    */
    void SetW(float w);

    /**
    Set the height of this collider rect.
    \param h Height
    */
    void SetH(float h);

    /**
    Set the width and height of this collider rect.
    \param w Width
    \param h Height
    */
    void SetWH(float w, float h);

    /**
    Returns the width of this collider rect.
    */
    float GetW() const;

    /**
    Returns the height of this collider rect.
    */
    float GetH() const;

    /**
    Set the x position of this collider rect.
    \param x X position
    */
    void SetX(float x);

    /**
    Set the x position of this collider rect.
    \param y Y position
    */
    void SetY(float y);

    /**
    Set the (x,y) position of this collider rect.
    \param x X position
    \param y Y position
    */
    void SetXY(float x, float y);

    /**
    Returns the x position of this collider rect.
    */
    const float GetX();

    /**
    Returns the y position of this collider rect.
    */
    const float GetY();

    /**
    Returns the SDL_FRect representing this collider.
    */
    SDL_FRect GetRectangle() const;

private:

    /**
    The rectangle representing the space this collider takes up.
    */
    SDL_FRect mRectangle{ 20.0f,20.0f,32.0f,32.f };
};
