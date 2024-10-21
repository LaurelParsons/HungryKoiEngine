#include <SDL3/SDL.h>
#include <cstdlib>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>

#include "Application.hpp"
#include "InputComponent.hpp"
#include "Collider2DComponent.hpp"

Application::Application(int width, int height) {
    this->width = width;
    this->height = height;
    SDLStartUp();

    //StartScene();
}
Application::~Application() {
    SDLShutDown();
}
void Application::SDLStartUp() {

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("unable to init SDL: %s", SDL_GetError());
    }
    else {
        window = SDL_CreateWindow("Hello SDL", width, height, SDL_WINDOW_OPENGL);
        renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);

        if (NULL == renderer) {
            SDL_Log("Error creating renderer");
        }
    }
}

void Application::StartScene() {
    mScene.StartUp(renderer, width, height);
    //mScene.AddPlayerEntity("./assets/hero.bmp", 25, 25, 5);
    //mScene.AddEnemyEntity("./assets/enemy.bmp", 200, 200, 1);
    mScene.SetSceneActive(true);
}

void Application::AddPlayerToScene(std::string filepath, int xPos, int yPos, int score) {
    mScene.AddPlayerEntity(filepath, xPos, yPos, score);
}

void Application::AddEnemyToScene(std::string filepath, int xPos, int yPos, int score) {
    mScene.AddEnemyEntity(filepath, xPos, yPos, score);
}

void Application::AddEnemyToSceneAtSecondsDelay(std::string filepath, int xPos, int yPos, int score, int seconds) {
}

void Application::SDLShutDown() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::Input(float deltaTime) {
    SDL_Event event;
    // Processing input
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            SDL_Log("Program quit %li", event.quit.timestamp);
            mScene.SetSceneActive(false);
        }
    }
    mScene.Input(deltaTime);
}
void Application::Update(float deltaTime) {
    mScene.Update(deltaTime);
}

void Application::Render() {
    mScene.Render();

}

void Application::Loop(float targetFPS) {

    Uint64 lastTime, currentTime;

    lastTime = SDL_GetTicks();
    Uint64 framesElapsed = 0;
    //target
    float deltaTime = 1.0f / targetFPS;
    while (mScene.IsSceneActive()) {
        Uint64 startOfFrame = SDL_GetTicks();
        Input(deltaTime);
        Update(deltaTime);
        Render();
        framesElapsed++;
        Uint64 elapsedTime = SDL_GetTicks() - startOfFrame;


        currentTime = SDL_GetTicks();
        //frame cap
        if (elapsedTime < (1000 / targetFPS)) {
            Uint64 delay = (1000 / targetFPS) - elapsedTime;
            SDL_Delay(delay);
            //SDL_Log("delaying by: %li", delay);
        }

        if (currentTime > lastTime + 1000) {
            deltaTime = 1.0f / framesElapsed;
            framesElapsed = 0;
            lastTime = SDL_GetTicks();
        }
    }
}
