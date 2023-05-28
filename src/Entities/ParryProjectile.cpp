#include <Entities/ParryProjectile.h>
#include <Helpers/Helpers.h>

ParryProjectile::ParryProjectile(QPointF pos, QPointF dir) : Projectile(1000, {10, 10}, pos)
{
    damage = 2;
    direction = normalize(dir);
    speed = 1000;
    setTeam(TEAM::PLAYER);
}