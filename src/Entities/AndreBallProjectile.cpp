#include <Entities/AndreBallProjectile.h>
#include <Helpers/Helpers.h>
#include <QDebug>

AndreBallProjectile::AndreBallProjectile(QPointF pos, QPointF dir) : Projectile(1000.0, {20, 20}, pos)
{
    damage = 5.0;
    direction = normalize(dir);
    speed = 1000.0;
    setTeam(TEAM::ENEMY);
}

void AndreBallProjectile::setState(int _state)
{
    switch(_state) {
        case AndreBallProjectile::STATE::DEFAULT:
            state = _state;
            break;
        case AndreBallProjectile::STATE::DESTROYED:
            state = _state;
            break;
        default:
            break;
    }
}