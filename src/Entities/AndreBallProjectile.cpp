#include <Entities/AndreBallProjectile.h>
#include <Helpers/Helpers.h>
#include <QDebug>

AndreBallProjectile::AndreBallProjectile(QPointF pos, QPointF dir) : Projectile(1000.0, {20, 20}, pos)
{
    damage = 2.0;
    direction = normalize(dir);
    speed = 1000.0;
    setTeam(TEAM::ENEMY);
}