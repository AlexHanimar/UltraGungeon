#include <Entities/Projectile.h>

void Projectile::setHitbox(AbstractHitbox *_hitbox)
{
    hitbox = _hitbox;
}

void Projectile::setHurtbox(AbstractHitbox *_hurtbox)
{
    hurtbox = _hurtbox;
}

void Projectile::setDamage(qreal _damage)
{
    damage = _damage;
}

void Projectile::setPierce(int _pierce)
{
    pierce = _pierce;
}

qreal Projectile::getDamage() const
{
    return damage;
}

AbstractHitbox* Projectile::getHitbox() const
{
    return hitbox;
}

AbstractHitbox* Projectile::getHurtbox() const
{
    return hurtbox;
}

int Projectile::getPierce() const
{
    return pierce;
}