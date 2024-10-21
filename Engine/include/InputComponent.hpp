#pragma once
#include <memory>
#include <string>
#include <SDL3/SDL.h>

#include "Component.hpp"

/**
* Component that handles user input.
*
* Represents a component that polls for user input, then moves the game entity based on what it receives.
*/
struct InputComponent : public Component {

    /**
    Creates a new input component.
    */
    InputComponent();

    /**
    Destroys this input component.
    */
    ~InputComponent();

    /**
    Polls for user input.

    Collects input, then applies movement to the game entity's transform component based on arrow key input.
    */
    void Input(float deltaTime) override;

    /**
    Returns ComponentType.InputComponent.
    */
    ComponentType GetType() override;

private:

    /**
    Speed of the game entity
    */
    float mSpeed{ 150.0 };
};
