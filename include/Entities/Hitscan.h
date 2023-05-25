#pragma once

#include <BasicObjects/AbstractHitbox.h>
#include <Helpers/Helpers.h>

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
public:
    enum STATE {
        DEFAULT = 0,
        FULL = 1,
        DESTROYED = 2
    };

    using GameObject::GameObject;

    [[nodiscard("Hitscan::getState() unused")]] virtual int getState() const;
    virtual void setState(int _state);

    virtual void addPierce(AbstractHitbox* hitbox);
    [[nodiscard("Hitscan::getStartPoint() unused")]] virtual QPointF getStartPoint() const;
    [[nodiscard("Hitscan::getEndpoint() unused")]] virtual QPointF getEndpoint() const;
    [[nodiscard("Hitscan::getDamage() unused")]] virtual qreal getDamage() const;

    void init(QPointF _pos, QPointF _dir, int _pierce, qreal _damage, qreal _maxLifeTime);
    void update(qreal deltaT);
};

Hitscan* _pistol1(QPointF pos, QPointF dir);