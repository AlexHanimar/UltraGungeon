#pragma once

#include <Entities/NonPlayerEntity.h>
#include <Entities/Hitbox.h>
#include <Entities/Projectile.h>

#include <vector>

class AbstractEnemyAI {
protected:
    Hitbox* hitbox;
    AbstractHitbox* hurtbox;
    qreal maxSpeed;
    qreal maxForce;
    Projectile* projectile;
    qreal projectileSpawnSpeed;
    RelativePosition* projectileSpawnPoint;
public:
    AbstractEnemyAI() = default;
    virtual void setHurtbox(AbstractHitbox* _hurtbox);
    virtual void setHitbox(Hitbox* _hitbox);
    virtual void setMaxSpeed(qreal _maxSpeed);
    virtual void setMaxForce(qreal _maxForce);
    virtual void setProjectile(Projectile* _projectile);
    virtual void setProjectileSpawnPoint(RelativePosition* _projectileSpawnPoint);
    virtual void setProjectileSpawnSpeed(qreal _projectileSpawnSpeed);

    [[nodiscard("AbstractEnemyAI::getHitbox() unused")]] virtual Hitbox* getHitbox() const;
    [[nodiscard("AbstractEnemyAI::getHurtbox() unused")]] virtual AbstractHitbox* getHurtbox() const;
    [[nodiscard("AbstractEnemyAI::getMaxSpeed() unused")]] virtual qreal getMaxSpeed() const;
    [[nodiscard("AbstractEnemyAI::getMaxForce() unused")]] virtual qreal getMaxForce() const;

    [[nodiscard("AbstractEnemyAI::getTargetVelocity() unused")]] virtual QPointF getTargetVelocity() const = 0;
    [[nodiscard("AbstractEnemyAI::spawnProjectile() unused")]] virtual Projectile* spawnProjectile(QPointF direction);
};

class AbstractEnemy : public NonPlayerEntity {
protected:
    AbstractEnemyAI* ai;
public:
    using NonPlayerEntity::NonPlayerEntity;
    virtual void init() = 0;
    virtual void update(qreal deltaT);
    [[nodiscard("AbstractEnemy::getAI() unused")]] virtual AbstractEnemyAI* getAI() const;
};