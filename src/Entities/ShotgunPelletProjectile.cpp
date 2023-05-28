#include <Entities/ShotgunPelletProjectile.h>
#include <Helpers/Helpers.h>
#include <random>
#include <QDebug>

ShotgunPelletProjectile::ShotgunPelletProjectile(QPointF pos, QPointF dir) : Projectile(200, {2, 2}, pos)
{
    static std::mt19937 gen(time(NULL));
    std::uniform_real_distribution<qreal> rndA(-0.1, 0.1);
    qreal angle = rndA(gen);
    auto rotate = QPointF(cos(angle), sin(angle));
    damage = 0.4;
    direction = normalize(dir);
    direction = {rotate.x() * direction.x() - rotate.y() * direction.y()
                 , rotate.y() * direction.x() + rotate.x() * direction.y()};
    std::uniform_real_distribution<qreal> rndS(0.8, 1.0);
    speed = 200 * rndS(gen);
    lifeTime = maxLifeTime;
    ShotgunPelletProjectile::setState(ShotgunPelletProjectile::STATE::DEFAULT);
    setTeam(TEAM::PLAYER);
}

void ShotgunPelletProjectile::update(qreal deltaT)
{
    lifeTime -= deltaT;
    if(lifeTime < 0)
        setState(ShotgunPelletProjectile::STATE::DESTROYED);
    moveBy(getVelocity() * deltaT);
}