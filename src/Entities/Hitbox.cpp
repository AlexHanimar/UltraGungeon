#include <Entities/Hitbox.h>

void Hitbox::setDamage(qreal _damage)
{
    damage = _damage;
}

void Hitbox::setActive(bool _active)
{
    active = _active;
}

qreal Hitbox::getDamage() const
{
    return damage;
}

bool Hitbox::isActive() const
{
    return active;
}