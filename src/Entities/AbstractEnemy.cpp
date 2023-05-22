#include <Entities/AbstractEnemy.h>

QPointF AbstractEnemy::getDestination() const
{
    return destination;
}

int AbstractEnemy::getState() const
{
    return state;
}

void AbstractEnemy::setDestination(QPointF _destination)
{
    destination = _destination;
}

qreal AbstractEnemy::getHealth() const
{
    return health;
}

qreal AbstractEnemy::getMaxHealth() const
{
    return maxHealth;
}

void AbstractEnemy::applyDamage(qreal damage)
{
    health -= damage;
}