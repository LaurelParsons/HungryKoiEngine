#pragma once

#include "GameEntity.hpp"
#include "TextureComponent.hpp"
#include "Scene.hpp"

/**
* Game entity that represents an enemy in the scene.
*
* Enemies have special movement behavior and will chase after the player on their turn.
*/
struct EnemyGameEntity : public GameEntity {

    /**
    Creates a new enemy entity with a reference to the current scene.

    \param scene The currently running scene
    */
    EnemyGameEntity(Scene* scene);

    /**
    Destroys this enemy.
    */
    virtual ~EnemyGameEntity();

    /**
    Updates this enemy.

    Determines movement behavior of the enemy entity, moving it towards the player.

    \param deltaTime Time since last frame
    */
    virtual void Update(float deltaTime) override;

private:

    /**
    The currently running scene.
    */
    Scene* currentScene;

    /**
    The speed of this enemy.
    */
    float mSpeed{ 100.0f };
};
