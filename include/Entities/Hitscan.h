#pragma once

#include <BasicObjects/AbstractHitbox.h>
#include <Helpers/Helpers.h>
#include <Entities/Teams.h>

class Hitscan : public GameObject {
protected:
    qreal damage;
    int pierce;
    QPointF position;
    QPointF direction;

    std::vector<AbstractHitbox*> pierced;

    qreal lifeTime;
    qreal maxLifeTime;
    int state;

    TEAM team;

    QPointF endpoint;
public:
    enum STATE {
        CHARGED = 0,
        DEFAULT = 1,
        DISCHARGED = 2,
        DESTROYED = 3
    };

    Hitscan(qreal _damage, int _pierce, QPointF _pos, QPointF _dir, qreal _lifetime, TEAM _team);

    [[nodiscard("Hitscan::getState() unused")]] virtual int getState() const;
    virtual void setState(int _state);

    virtual void addPierce(AbstractHitbox* hitbox);
    [[nodiscard("Hitscan::getStartPoint() unused")]] virtual QPointF getStartPoint() const;
    [[nodiscard("Hitscan::getEndpoint() unused")]] virtual QPointF getEndpoint() const;
    [[nodiscard("Hitscan::getDamage() unused")]] virtual qreal getDamage() const;
    [[nodiscard("Hitscan::pierces() unused")]] virtual bool pierces(AbstractHitbox* hitbox) const;

    void update(qreal deltaT);
};