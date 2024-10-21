#include <SDL3/SDL.h>
#include <cstdlib>
#include <vector>
#include <memory>
#include <fstream>

#include "Application.hpp"
#include "InputComponent.hpp"
#include "Collider2DComponent.hpp"
#include "Scene.hpp"
#include "Vector2.hpp"

Scene::Scene() {
}
Scene::~Scene() {
    ShutDown();
}
void Scene::StartUp(SDL_Renderer* renderer, int width, int height) {
    mRenderer = renderer;
    this->width = width;
    this->height = height;

    backgroundGE = std::make_shared<GameEntity>();
    backgroundGE->AddDefaultTransform();
    backgroundGE->GetTransform()->SetXY(Vector2(0, 0));
    backgroundGE->GetTransform()->SetWH(width, height);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>();
    texture->CreateSprite(renderer, "./../assets/pond_bottom.bmp");
    backgroundGE->AddComponent(texture);
}

void Scene::AddPlayerEntity(std::string filepath, int xPos, int yPos, int score) {
    mainCharacter = std::make_shared<GameEntity>();
    mainCharacter->AddDefaultTransform();
    mainCharacter->GetTransform()->SetXY(Vector2(xPos, yPos));

    std::shared_ptr<TextureComponent> characterSprite = std::make_shared<TextureComponent>();
    characterSprite->CreateSprite(mRenderer, filepath);
    mainCharacter->AddComponent(characterSprite);
    mainCharacter->SetScore(score);

    std::shared_ptr<InputComponent> inputController = std::make_shared<InputComponent>();
    mainCharacter->AddComponent(inputController);

    std::shared_ptr<Collider2DComponent> collider = std::make_shared<Collider2DComponent>();
    mainCharacter->AddComponent(collider);

}

void Scene::AddEnemyEntity(std::string filepath, int xPos, int yPos, int score) {
    std::shared_ptr<EnemyGameEntity> e = std::make_shared<EnemyGameEntity>(this);
    e->AddDefaultTransform();
    e->GetTransform()->SetXY(Vector2(xPos, yPos));

    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>();
    texture->CreateSprite(mRenderer, filepath);
    e->AddComponent(texture);

    std::shared_ptr<Collider2DComponent> collider = std::make_shared<Collider2DComponent>();
    e->AddComponent(collider);

    e->SetScore(score);

    enemies.push_back(std::move(e));
}

void Scene::ShutDown() {
}

void Scene::Input(float deltaTime) {
    //Handle sdl get keyboard state AFTER your sdl pollEvent
    mainCharacter->Input(deltaTime);
}
void Scene::Update(float deltaTime) {
    mainCharacter->Update(deltaTime);
    bool enemies_alive = false;
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->Update(deltaTime);

        bool enemyHit = enemies[i]->Intersects(mainCharacter);

        bool gameOver = false;

        if (enemyHit && enemies[i]->IsRenderable()) {
            if (enemies[i]->GetScore() > mainCharacter->GetScore()) {
                gameOver = true;
            }
            else {
                enemies[i]->setRenderable(false);
                mainCharacter->SetScore(mainCharacter->GetScore() + enemies[i]->GetScore());
                SDL_Log("Your score is %i", mainCharacter->GetScore());
            }
        }

        if(enemies[i]->IsRenderable()) {
            enemies_alive = true;
        }


        if (gameOver) {
            SDL_Log("You lose!");
            SDL_Log("Your score is %i", mainCharacter->GetScore());
            SDL_Log("Enemy %i got you. Is renderable?: %i", i, enemies[i]->IsRenderable());
            sceneActive = false;
        }
    }

    if (!enemies_alive) {
            SDL_Log("You win!");
            sceneActive = false;
    }
}

void Scene::Render() {
    SDL_RenderClear(mRenderer);
    backgroundGE->Render(mRenderer);

    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->IsRenderable())
            enemies[i]->Render(mRenderer);
    }

    mainCharacter->Render(mRenderer);

    SDL_RenderPresent(mRenderer);
}

Vector2 Scene::GetPlayerPosition() { //return x,y position of the player character
    auto mc_transform = mainCharacter->GetComponent<TransformComponent>(ComponentType::TransformComponent);

    return mc_transform->GetPosition();
}

void Scene::SetSceneActive(bool status) {
    sceneActive = status;
}

bool Scene::IsSceneActive() const {
    return sceneActive;
}
