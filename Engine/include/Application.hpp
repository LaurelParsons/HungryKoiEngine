#pragma once
#include <vector>

#include "GameEntity.hpp"
#include "TextureComponent.hpp"
#include "EnemyGameEntity.hpp"
#include "Scene.hpp"

/**
* Game application that handles running the scene.
*
* This class creates a scene with the given parameters and allows external sources to add game objects.
* Once scene is set up, Loop will start the game loop.
*/

struct Application {

    /**
    Initialize the application with a given screen width and height.

    \param width The screen width of the application
    \param height The screen height of the application
    */
    Application(int width, int height);

    /**
    Destroy the application.
    */
    ~Application();

    /**
    Starts the SDL window and renderer.
    */
    void SDLStartUp();

    /**
    Starts the scene.

    Passes the renderer and specified size to the scene, then marks it as active.
    */
    void StartScene();

    /**
    Add a player entity to the scene.

    Adds a game object to be set as the main character for the current scene with the given values

    \param filepath Path to the gameobject's image source
    \param xPos The starting x position of the gameobject
    \param yPos The starting y position of the gameobject
    \param score The starting score of the gameobject
    */
    void AddPlayerToScene(std::string filepath, int xPos, int yPos, int score);

    /**
    Add an enemy entity to the scene.

    Adds a game object to the scene which will be added to the list of enemies.

    \param filepath Path to the gameobject's image source
    \param xPos The starting x position of the gameobject
    \param yPos The starting y position of the gameobject
    \param score The starting score of the gameobject
    */
    void AddEnemyToScene(std::string filepath, int xPos, int yPos, int score);

    void AddEnemyToSceneAtSecondsDelay(std::string filepath, int xPos, int yPos, int score, int seconds);

    /**
    Shuts down currently active SDL entities.

    Safely destroys SDL window and quits SDL.
    */
    void SDLShutDown();

    /**
    Polls for input.

    Checks if the user quit out of the application, in which case the application is shut down.
    Otherwise, passes the polled input into the scene.
    */
    void Input(float deltaTime);

    /**
    Calls update on the scene.
    \param deltaTime Time since Update was last called
    */
    void Update(float deltaTime);

    /**
    Calls render on the scene.
    */
    void Render();

    /**
    Runs the game loop.

    Calls the Input, Update, and Render methods to manage the scene's game loop.
    Handles the timekeeping, keeping track of DeltaTime and delaying the process if necessary.
    */
    void Loop(float targetFPS);

private:

    /**
    Width of the application window.
    */
    int width;

    /**
    Height of the application window.
    */
    int height;

    /**
    The current scene.

    Scene variable that the application is running. Contains all information about the current game
    */
    Scene mScene;

    /**
    SDL window the application is running within.
    */
    SDL_Window* window;

    /**
    SDL renderer handling drawing the game.
    */
    SDL_Renderer* renderer;
};
