#pragma once

#include <Entities/MovableEntity.h>

class Coin : public MovableEntity {
private:
    qreal lifeTime;
    qreal maxLifeTime = 1.5;

    int state;
    int spawnAction;

    std::vector<std::pair<int, GameObject*>> targetsObj;
    std::vector<QPointF> targets;
public:
    Coin(QPointF pos, QPointF dir, QPointF velocity);

    [[nodiscard("Coin::getState() unused")]] int getState() const;
    [[nodiscard("Coin::getSpawnAction() unused")]] int getSpawnAction() const;
    std::vector<QPointF>& getTargets();

    enum STATE {
        ACTIVE = 0,
        DEADCOIN = 1,
        DESTROYED = 2
    };

    enum SPAWN_ACTION {
        NONE = 0,
        PISTOL = 1,
        RAILGUN = 2
    };

    void setState(int _state);
    void setSpawnAction(int _spawnAction);

    void update(qreal deltaT) override;

    void addTarget(GameObject* obj, int prior);

    void makeTargetList();
};