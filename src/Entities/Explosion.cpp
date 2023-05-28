#include <Entities/Explosion.h>
#include <Helpers/Helpers.h>

Explosion::Explosion(QPointF pos, qreal rad, qreal _damage) : GameObject(pos)
{
    radius = rad;
    damage = _damage;
    state = Explosion::STATE::DEFAULT;
}

int Explosion::getState() const
{
    return state;
}

qreal Explosion::getDamage() const
{
    return damage;
}

qreal Explosion::getRadius() const
{
    return radius;
}

bool Explosion::overlapsWith(GameObject *obj)
{
    return (module(obj->getAbsolutePosition() - getAbsolutePosition()) <= radius);
}

void Explosion::setState(int _state)
{
    switch(_state) {
        case Explosion::STATE::DEFAULT:
            state = _state;
            break;
        case Explosion::STATE::INACTIVE:
            state = _state;
            lifeTime = maxLifeTime;
            break;
        case Explosion::STATE::DESTROYED:
            state = _state;
            break;
        default:
            break;
    }
}

void Explosion::update(qreal deltaT)
{
    if(state == Explosion::STATE::INACTIVE) {
        lifeTime -= deltaT;
        if(lifeTime < 0)
            setState(Explosion::STATE::DESTROYED);
    }
}