#include <Entities/Projectile.h>
#include <Helpers/Helpers.h>
#include <QDebug>

int Projectile::getState() const
{
    return state;
}

TEAM Projectile::getTeam() const
{
    return team;
}

qreal Projectile::getDamage() const
{
    return damage;
}

void Projectile::setDamage(qreal _damage)
{
    damage = _damage;
}

void Projectile::setTeam(TEAM _team)
{
    team = _team;
}

void Projectile::setState(int _state)
{
    switch(_state) {
        case Projectile::STATE::DEFAULT:
            state = Projectile::STATE::DEFAULT;
            break;
        case Projectile::STATE::DESTROYED:
            state = Projectile::STATE::DESTROYED;
            break;
        default:
            break;
    }
}

Projectile* pistol2(QPointF pos, QPointF dir)
{
    auto* res = new Projectile(500, {6, 6}, pos);
    res->setVelocity(normalize(dir) * 500.0);
    res->setDamage(1.0);
    res->setTeam(TEAM::PLAYER);
    return res;
}

Projectile* shotgun2(QPointF pos, QPointF dir)
{
    return pistol2(pos, dir);
}
Projectile* railgun2(QPointF pos, QPointF dir)
{
    return pistol2(pos, dir);
}