#pragma once

#include <BasicObjects/AbstractEntity.h>

class MovableEntity : public AbstractEntity {
protected:
    QPointF direction = {0, 0};
    qreal speed = 0;
    qreal maxSpeed;
public:
    MovableEntity(qreal _maxSpeed, QSizeF _size, QPointF _position = {0, 0}, GameObject* _parent = nullptr);
    virtual void setDirection(QPointF _ndirection);
    virtual void setSpeed(qreal _speed);
    virtual void setMaxSpeed(qreal _maxSpeed);
    virtual void setVelocity(QPointF _velocity);
    [[nodiscard("MovableEntity::getSpeed() unused")]] virtual qreal getSpeed() const;
    [[nodiscard("MovableEntity::getDirection() unused")]] virtual QPointF getDirection() const;
    [[nodiscard("MovableEntity::getVelocity() unused")]] virtual QPointF getVelocity() const;
    [[nodiscard("MovableEntity::getMaxSpeed() unused")]]virtual qreal getMaxSpeed() const;
    virtual void update(qreal deltaT);

    virtual ~MovableEntity() noexcept = default;
};
