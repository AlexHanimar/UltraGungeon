#pragma once

#include <Entities/NonPlayerEntity.h>

class Projectile : public NonPlayerEntity {
protected:
    AbstractHitbox* hitbox;
    AbstractHitbox* hurtbox;
    qreal damage;
    int pierce;
public:
    using NonPlayerEntity::NonPlayerEntity;
    virtual void setDamage(qreal _damage);
    virtual void setHitbox(AbstractHitbox* _hitbox);
    virtual void setHurtbox(AbstractHitbox* _hurtbox);
    virtual void setPierce(int _pierce);
    [[nodiscard("Projectile::getDamage() unused")]] virtual qreal getDamage() const;
    [[nodiscard("Projectile::getHitbox() unused")]] virtual AbstractHitbox* getHitbox() const;
    [[nodiscard("Projectile::getHurtbox() unused")]] virtual AbstractHitbox* getHurtbox() const;
    [[nodiscard("Projectile::getPierce() unused")]] virtual int getPierce() const;
};