#pragma once

#include <Entities/MovableEntity.h>
#include <Entities/Teams.h>

class AbstractEnemy : public MovableEntity {
protected:
    qreal health;
    qreal maxHealth;
    int state;
    qreal defaultSpeed;
    QPointF destination;
public:
    using MovableEntity::MovableEntity;

    [[nodiscard("AbstractEnemy::getState() unused")]] virtual int getState() const;
    [[nodiscard("AbstractEnemy::getDestination() unused")]] virtual QPointF getDestination() const;
    [[nodiscard("AbstractEnemy::getHealth() unused")]] virtual qreal getHealth() const;
    [[nodiscard("AbstractEnemy::getMaxHealth() unused")]] virtual qreal getMaxHealth() const;
    virtual void applyDamage(qreal damage);
    virtual void setDestination(QPointF _destination);
    virtual void init() = 0;
    virtual void setState(int _state) = 0;

    virtual ~AbstractEnemy() = default;

};