#include <memory>
#include <cmath>

#include "EnemyGameEntity.hpp"
#include "Collider2DComponent.hpp"
#include "Scene.hpp"

EnemyGameEntity::EnemyGameEntity(Scene* scene) {
    currentScene = scene;
}
EnemyGameEntity::~EnemyGameEntity() {

}
void EnemyGameEntity::Update(float deltaTime) {
    Vector2 playerPos = currentScene->GetPlayerPosition();

    auto ref = GetComponent<TransformComponent>(ComponentType::TransformComponent);
    Vector2 enemyPosition = ref->GetPosition();
    float step = mSpeed * deltaTime;
    ref->SetXY(enemyPosition.MoveTowards(playerPos, step));
    float rads = atan2(enemyPosition.y - playerPos.y, enemyPosition.x - playerPos.x);
    ref->SetAngle((rads * 180 / (2 * acos(0.0))) - 90.0);

    for (auto& [key, value] : mComponents) {
        mComponents[key]->Update(deltaTime);
    }

    for (auto& children : mGameEntities) {
        children->Update(deltaTime);
    }
}
