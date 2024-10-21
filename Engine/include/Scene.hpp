#pragma once
#include <vector>

#include "GameEntity.hpp"
#include "TextureComponent.hpp"
#include "Vector2.hpp"

/**
Represents the current game being played.

A scene contains all the game objects currently in the game and handles passing them input, updating, and rendering them.
*/
struct Scene {

    /**
    Create a new scene.
    */
    Scene();

    /**
    Destroy this scene.
    */
    ~Scene();

    /**
    Start this scene with a given width and height.

    Passes the scene the renderer and size information it needs to run, along with setting up the background.

    \param renderer SDL_Renderer the scene will use to draw
    \param width Width of the scene window
    \param height Height of the scene window
    */
    void StartUp(SDL_Renderer* renderer, int width, int height);

    /**
    Adds a game entity to the scene and sets it as the main character.

    \param filepath Path to the image for the game entity's texture
    \param xPos Starting x position of the game entity
    \param yPos Starting y position of the game entity
    \param score Starting score of the game entity
    */
    void AddPlayerEntity(std::string filepath, int xPos, int yPos, int score);

    /**
    Adds a game entity to the scene and puts it in the list of enemies.

    \param filepath Path to the image for the game entity's texture
    \param xPos Starting x position of the game entity
    \param yPos Starting y position of the game entity
    \param score Starting score of the game entity
    */
    void AddEnemyEntity(std::string filepath, int xPos, int yPos, int score);

    /**
    Shut down the current scene.
    */
    void ShutDown();

    /**
    Passes player input to the main character.
    \param deltaTime Time since last frame
    */
    void Input(float deltaTime);

    /**
    Updates game objects and checks for game over conditions.

    Calls update on all game objects, as well as checking for collision between the main character and any enemies.
    If the main character has been eaten, the game is ended with a player loss. If no enemies remain, the game ends with a player win.
    \param deltaTime Time since last frame
    */
    void Update(float deltaTime);

    /**
    Renders all game entities contained in the scene.
    */
    void Render();

    /**
    Returns the (x, y) position of the main character as a Vector2.
    */
    Vector2 GetPlayerPosition();

    /**
    Sets the scene active or inactive based on the value of status.

    \param status True for active, false for inactive
    */
    void SetSceneActive(bool status);

    /**
    Returns a boolean representing if the scene is active.
    */
    bool IsSceneActive() const;

private:

    /**
    List of all enemy game entities in the scene.
    */
    std::vector<std::shared_ptr<GameEntity>> enemies;

    /**
    The game entity representing the player.
    */
    std::shared_ptr<GameEntity> mainCharacter;

    /**
    Game entity that holds the background image.
    */
    std::shared_ptr<GameEntity> backgroundGE;

    /**
    Boolean representing whether this scene is active.
    */
    bool sceneActive{ false };

    /**
    Renderer used to draw the scene.
    */
    SDL_Renderer* mRenderer;

    /**
    Width of the scene window
    */
    int width;

    /**
    Height of the scene window
    */
    int height;
};
