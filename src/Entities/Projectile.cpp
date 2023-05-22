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

Projectile* pistol1(QPointF pos, QPointF dir)
{
    auto* res = new Projectile(500, {6, 6}, pos);
    res->setVelocity(normalize(dir) * 500.0);
    res->setDamage(1);
    res->setTeam(TEAM::PLAYER);
    return res;
}

Projectile* pistol2(QPointF pos, QPointF dir)
{
    auto* res = new Projectile(500, {6, 6}, pos);
    res->setVelocity(normalize(dir) * 500.0);
    res->setDamage(1.0);
    res->setTeam(TEAM::PLAYER);
    return res;
}

Projectile* pellet(QPointF pos, QPointF dir)
{
    dir = normalize(dir);
    auto* res = new Projectile(300, {6, 6}, pos);
    res->setVelocity(dir * 500);
    res->setDamage(0.5);
    res->setTeam(TEAM::PLAYER);
    return res;
}

std::vector<Projectile*> shotgun1(QPointF pos, QPointF dir)
{
    qreal angle = 0.1;
    dir = normalize(dir);
    std::vector<Projectile*> res;
    res = {pellet(pos, dir), pellet(pos, rotate(dir, angle)), pellet(pos, rotate(dir, -angle))};
    return res;
}

Projectile* shotgun2(QPointF pos, QPointF dir)
{
    return pistol1(pos, dir);
}
Projectile* railgun1(QPointF pos, QPointF dir)
{
    return pistol1(pos, dir);
}
Projectile* railgun2(QPointF pos, QPointF dir)
{
    return pistol1(pos, dir);
}