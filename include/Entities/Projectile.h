#pragma once

#include <Entities/MovableEntity.h>
#include <Entities/Teams.h>

class Projectile : public MovableEntity {
protected:
    int state;
    qreal damage;
    TEAM team;
public:
    enum STATE {
        DEFAULT = 0,
        DESTROYED = 1
    };
    using MovableEntity::MovableEntity;
    virtual void setDamage(qreal _damage);
    [[nodiscard("Projectile::getDamage() unused")]] virtual qreal getDamage() const;
    void setTeam(TEAM _team);
    [[nodiscard("Projectile::getTeam() unused")]] virtual TEAM getTeam() const;
    virtual void setState(int _state);
    [[nodiscard("Projectile::getState() unused")]] virtual int getState() const;

    virtual ~Projectile() noexcept = default;
};

Projectile* pistol1(QPointF pos, QPointF dir);
Projectile* pistol2(QPointF pos, QPointF dir);
std::vector<Projectile*> shotgun1(QPointF pos, QPointF dir);
Projectile* shotgun2(QPointF pos, QPointF dir);
Projectile* railgun1(QPointF pos, QPointF dir);
Projectile* railgun2(QPointF pos, QPointF dir);

Projectile* andreBall(QPointF pos, QPointF dir);