#pragma once

#include <Entities/AbstractEnemy.h>

class EnemyAndre : public AbstractEnemy {
protected:
    qreal bodyDamage;

    qreal defaultSpeed;
    qreal dashSpeed;
    qreal recoverySpeed;

    qreal dashTimer;
    qreal maxDashTimer;
    qreal chargeUpTimer;    // for projectile attack
    qreal maxChargeUpTimer; // for projectile attack
    qreal recoveryTimer;
    qreal maxRecoveryTimer;

    qreal dashRadius;
    bool hitboxActive;

    int spawnAction;
    QPointF spawnDirection;
public:
    EnemyAndre(QPointF pos);

    enum STATE {
        DEFAULT = 0,
        DASHING = 1,
        SHOOTING = 2,
        RECOVERY = 3
    };

    enum SPAWN_ACTION {
        NONE = 100000,
        BALL = 0
    };

    void setState(int _state) override;
    void update(qreal deltaT) override;
    void init() override;


    [[nodiscard("EnemyAndre::getDamage() unused")]] qreal getDamage() const;

    [[nodiscard("EnemyAndre::hitboxIsActive() unused")]] bool hitboxIsActive() const;
    void setHitboxActive(bool _nactive);

    void setSpawnAction(int _spawn_action);
    [[nodiscard("EnemyAndre::getSpawnAction() unused")]] int getSpawnAction() const;
    void setSpawnDirection(QPointF _spawn_direction);
    [[nodiscard("EnemyAndre::getSpawnDirection() unused")]] QPointF getSpawnDirection() const;
};