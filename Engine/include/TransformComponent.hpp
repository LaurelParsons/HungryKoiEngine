#pragma once
#include <memory>
#include <string>
#include <SDL3/SDL.h>

#include "Component.hpp"
#include "Vector2.hpp"

/**
* Component that controls the placement of a game entity.
*
* This component holds an SDL_FRect representing the location of its game object in the scene. It can be used to
* change the size and position of the game object.
*/
struct TransformComponent : public Component {

    /**
    Creates a new transform component with default values.
    */
    TransformComponent();

    /**
    Destroys this transform component.
    */
    ~TransformComponent();

    /**
    Updates the width of the transform component.

    Updates the transform to grow as the game entity's score grows.
    */
    void Update(float deltaTime) override;

    /**
    Returns ComponentType.TransformComponent
    */
    ComponentType GetType() override;

    /**
    Set the width of the transform rect.
    \param w Width
    */
    void SetW(float w);

    /**
    Set the height of the transform rect.
    \param h Height
    */
    void SetH(float h);

    /**
    Set the width and height of the transform rect.
    \param w Width
    \param h Height
    */
    void SetWH(float w, float h);

    /**
    Returns the width of the transform rect.
    */
    float GetW() const;

    /**
    Returns the height of the transform rect.
    */
    float GetH() const;

    /**
    Set the x position of the transform rect.
    \param x X position
    */
    void SetX(float x);

    /**
    Set the x position of the transform rect.
    \param y Y position
    */
    void SetY(float y);

    /**
    Set the (x,y) position of the transform rect with a Vector2.
    \param position A Vector2 containing the (x, y) position to move to
    */
    void SetXY(Vector2 position);

    /**
    Returns the x position of the transform rect.
    */
    const float GetX();

    /**
    Returns the y position of the transform rect.
    */
    const float GetY();

    /**
    Returns the angle the transform is rotated at.
    */
    const float GetAngle();

    /**
    Sets the angle of rotation for this transform.

    \param angle Angle to rotate to.
    */
    void SetAngle(float angle);

    /**
    Returns the position of the transform as a Vector2.
    */
    const Vector2 GetPosition();

    /**
    Returns the SDL_FRect that represents the position and size of the game entity.
    */
    SDL_FRect GetRectangle() const;

private:

    /**
    The SDL_FRect that represents the position and size of the game entity.
    */
    SDL_FRect mRectangle{ 20.0f,20.0f,32.0f,32.f };

    /**
    Default starting width of the game entity.
    */
    float startingW = 32.0;

    /**
    Default starting height of the game entity.
    */
    float startingH = 32.0;

    /**
    Angle of the game entity.
    */
    float angle = 0;
};
