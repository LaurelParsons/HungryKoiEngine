#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <map>
#include <vector>

#include "ComponentType.hpp"
#include "Component.hpp"
#include "TextureComponent.hpp"
#include "TransformComponent.hpp"

/**
* Represents an object that exists in the scene.
*
* Any object in the scene is a game entity. A game entity contains components which control its rendering and behavior,
* and can hold child game entities.
*/

struct GameEntity : public std::enable_shared_from_this<GameEntity> {

    /**
    Creates a new game entity.
    */
    GameEntity();

    /**
    Destroys this game entity.
    */
    virtual ~GameEntity();

    /**
    Returns a shared pointer to this game entity.
    */
    std::shared_ptr<GameEntity> GetThisPtr() {
        return shared_from_this();
    }

    /**
    Checks for input.

    Calls the Input function of all this game entity's components and children.

    \param deltaTime Time since last frame
    */
    virtual void Input(float deltaTime);

    /**
    Updates this game entity.

    Calls the Update function of all this game entity's components and children.

    \param deltaTime Time since last frame
    */
    virtual void Update(float deltaTime);

    /**
    Renders this game entity.

    Calls the Render function of all this game entity's components and children.

    \param renderer Renderer that will be used to draw
    */
    virtual void Render(SDL_Renderer* renderer);

    /**
    Adds a new component to this game entity.

    \param component Component of type T to be added
    */
    template<typename T>
    void AddComponent(std::shared_ptr<T> component);

    /**
    Returns the component of specified type from this game entity.

    \param type The ComponentType to return
    */
    template<typename T>
    std::shared_ptr<T> GetComponent(ComponentType type);

    /**
    Adds a TransformComponent with default values to this game entity.
    */
    void AddDefaultTransform();

    /**
    Returns this game entity's TransformComponent.
    */
    std::shared_ptr<TransformComponent> GetTransform();

    /**
    Adds a child game entity to this game entity.

    \param child The child game entity to add
    */
    void AddChildGameEntity(std::shared_ptr<GameEntity> child);

    /**
    Returns the child game entity at a specified index.

    \param index The index of the child to return
    */
    std::shared_ptr<GameEntity> GetChildGameEntityAtIndex(size_t index);

    /**
    Marks this game entity renderable.

    If a game entity is renderable, it will be displayed on the game screen.
    */
    void setRenderable(bool renderable);

    /**
    Checks if this game entity is renderable.
    */
    bool IsRenderable() const;

    /**
    Returns true if this game entity intersects with the game entity passed in.

    Checks if the collider components of both game entities overlap.
    If either game entity does not have a collider, will return false.

    \param e The other game entity to check collision with
    */
    bool Intersects(std::shared_ptr<GameEntity> e);

    /**
    Set the score value of this game entity.

    \param newScore Score value to be set
    */
    void SetScore(int newScore);

    /**
    Returns the score of this game entity.
    */
    int GetScore();

protected:
    /**
    Map of components this game entity contains.

    Map from ComponentType to Component.
    This design enforces that each game entity can only have one component of each type.
    */
    std::map<ComponentType, std::shared_ptr<Component>> mComponents;

    /**
    Boolean determining if the game entity should be rendered to the screen.
    */
    bool mRenderable{ true };

    /**
    List of child game entities.
    */
    std::vector<std::shared_ptr<GameEntity>> mGameEntities;

    /**
    Score value of this game entity.

    Represents how much growth this game entity has.
    Higher scoring game entities will eat lower scoring ones on contact,
    adding the consumed game entity's score to their own.
    */
    int score = 0;
};
