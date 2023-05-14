#pragma once

#include <BasicObjects/AbstractHitbox.h>

class Hitbox : public AbstractHitbox {
protected:
    qreal damage;
    bool active;
public:
    virtual void setDamage(qreal _damage);
    virtual void setActive(bool _active);
    [[nodiscard("Hitbox::getDamage() unused")]] virtual qreal getDamage() const;
    [[nodiscard("Hitbox::isActive() unused")]] virtual bool isActive() const;
};