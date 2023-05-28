#include <Entities/ShotgunPelletProjectile.h>
#include <Helpers/Helpers.h>
#include <random>

ShotgunPelletProjectile::ShotgunPelletProjectile(QPointF pos, QPointF dir) : Projectile(200, {2, 2}, pos)
{
    std::mt19937 gen(time(NULL));
    std::uniform_real_distribution<qreal> rnd(-0.2, 0.2);
    qreal angle = rnd(gen);
    auto rotate = QPointF(cos(angle), sin(angle));
    damage = 0.2;
    direction = normalize(dir);
    direction = {rotate.x() * direction.x() - rotate.y() * direction.y()
                 , rotate.y() * direction.x() + rotate.x() * direction.y()};
    speed = 200;
    setTeam(TEAM::PLAYER);
}