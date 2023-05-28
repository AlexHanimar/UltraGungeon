#pragma once

#include <BasicObjects/GameObject.h>

class Explosion : public GameObject {
private:
    qreal radius;
    qreal damage;
    int state;

    qreal lifeTime;
    qreal maxLifeTime = .5;
public:
    Explosion(QPointF pos, qreal rad, qreal _damage);

    enum STATE {
        DEFAULT = 0,
        INACTIVE = 1,
        DESTROYED = 2
    };

    bool overlapsWith(GameObject* obj);
    [[nodiscard("Explosion::getRadius() unused")]] qreal getRadius() const;
    [[nodiscard("Explosion::getDamage() unused")]] qreal getDamage() const;

    [[nodiscard("Explosion::getState() unused")]] int getState() const;
    void setState(int _state);

    void update(qreal deltaT);
};