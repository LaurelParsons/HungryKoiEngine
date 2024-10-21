#pragma once
#include <SDL3/SDL.h>
#include <memory>

#include "ComponentType.hpp"

//Forward declaration of GameEntity
struct GameEntity;

/**
* Base class for the component type.
*
* Represents a component that can be added to a game entity to control some aspect of its behavior.
* The Input, Update, and Render functions will be called on the game entity's Input, Update, and Render function respectively.
*/

struct Component {

    /**
    Creates a new component.
    */
	Component() {

	}

	/**
    Destroys this component.
    */
	virtual ~Component() {

	}

	/**
    Polls for input.
    */
	virtual void Input(float deltaTime) {

	}

	/**
    Updates component.
    */
	virtual void Update(float deltaTime) {

	}

	/**
    Renders component.
    */
	virtual void Render(SDL_Renderer* renderer) {

	}

	virtual ComponentType GetType() = 0;

	/**
    Sets the game entity that owns this component.
    \param g Game entity owning this component
    */
	void SetGameEntity(std::shared_ptr<GameEntity> g) {
		mGameEntity = g;
	}

	/**
    Returns the game entity that owns this component.
    */
	std::shared_ptr<GameEntity> getGameEntity() {
		return mGameEntity;
	}

private:

    /**
    The game entity that owns this component.
    */
	std::shared_ptr<GameEntity> mGameEntity;
};
