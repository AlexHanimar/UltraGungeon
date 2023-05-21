#include <Entities/MovableEntity.h>
#include <Helpers/Helpers.h>
#include <QDebug>

MovableEntity::MovableEntity(qreal _maxSpeed, QSizeF _size, QPointF _position, GameObject *_parent)
    : AbstractEntity(_size, _position, _parent)
    , maxSpeed(_maxSpeed) {}

void MovableEntity::setDirection(QPointF _ndirection)
{
    direction = normalize(_ndirection);
}

void MovableEntity::setSpeed(qreal _speed)
{
    speed = std::min(maxSpeed, _speed);
}

void MovableEntity::setMaxSpeed(qreal _maxSpeed)
{
    maxSpeed = _maxSpeed;
}

void MovableEntity::setVelocity(QPointF _velocity)
{
    setDirection(_velocity);
    setSpeed(std::min(maxSpeed, module(_velocity)));
}

QPointF MovableEntity::getVelocity() const
{
    return direction * speed;
}

qreal MovableEntity::getSpeed() const
{
    return speed;
}

QPointF MovableEntity::getDirection() const
{
    return direction;
}

qreal MovableEntity::getMaxSpeed() const
{
    return maxSpeed;
}


void MovableEntity::update(qreal deltaT)
{
    QPointF velocity = direction * speed;
    moveBy(velocity * deltaT);
}