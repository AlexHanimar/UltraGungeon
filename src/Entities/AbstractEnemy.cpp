#include <Entities/AbstractEnemy.h>

void AbstractEnemyAI::setHitbox(Hitbox *_hitbox)
{
    hitbox = _hitbox;
}

void AbstractEnemyAI::setHurtbox(AbstractHitbox *_hurtbox)
{
    hurtbox = _hurtbox;
}

void AbstractEnemyAI::setMaxForce(qreal _maxForce)
{
    maxForce = _maxForce;
}

void AbstractEnemyAI::setMaxSpeed(qreal _maxSpeed)
{
    maxSpeed = _maxSpeed;
}

Hitbox *AbstractEnemyAI::getHitbox() const
{
    return hitbox;
}

AbstractHitbox *AbstractEnemyAI::getHurtbox() const
{
    return hurtbox;
}

qreal AbstractEnemyAI::getMaxForce() const
{
    return maxForce;
}

qreal AbstractEnemyAI::getMaxSpeed() const
{
    return maxSpeed;
}

void AbstractEnemyAI::setProjectile(Projectile *_projectile)
{
    projectile = _projectile;
}

void AbstractEnemyAI::setProjectileSpawnPoint(RelativePosition* _projectileSpawnPoint)
{
    delete projectileSpawnPoint;
    projectileSpawnPoint = _projectileSpawnPoint;
}

void AbstractEnemyAI::setProjectileSpawnSpeed(qreal _projectileSpawnSpeed)
{
    projectileSpawnSpeed = _projectileSpawnSpeed;
}

Projectile *AbstractEnemyAI::spawnProjectile(QPointF direction)
{
    auto proj = new Projectile(projectileSpawnPoint->getAbsolutePos());
    proj->setPierce(projectile->getPierce());
    proj->setDamage(projectile->getDamage());
    proj->setMass(projectile->getMass());
    proj->setTeam(TEAM::ENEMY);
    qreal hHitbox = projectile->getHitbox()->bottom() - projectile->getHitbox()->top();
    qreal wHitbox = projectile->getHitbox()->right() - projectile->getHitbox()->left();
    auto projHitbox = new AbstractHitbox(proj->getPosRef(), {0, 0}, {hHitbox, wHitbox});
    proj->setHitbox(projHitbox);
    qreal hHurtbox = projectile->getHurtbox()->bottom() - projectile->getHurtbox()->top();
    qreal wHurtbox = projectile->getHurtbox()->right() - projectile->getHurtbox()->left();
    auto projHurtbox = new AbstractHitbox(proj->getPosRef(), {0, 0}, {hHurtbox, wHurtbox});
    proj->setHurtbox(projHurtbox);
    qreal hCollider = projectile->getCollider()->bottom() - projectile->getCollider()->top();
    qreal wCollider = projectile->getCollider()->right() - projectile->getCollider()->left();
    auto projCollider = new AbstractHitbox(proj->getPosRef(), {0, 0}, {hCollider, wCollider});
    proj->setCollider(projCollider);
    qreal directionMod = direction.x() * direction.x() + direction.y() * direction.y();
    directionMod = sqrt(directionMod);
    QPointF velocity = (directionMod != 0.0 ? direction / directionMod : QPointF(1, 0)) * projectileSpawnSpeed;
    proj->setVelocity(velocity);
    return proj;
}

void AbstractEnemy::update(qreal deltaT)
{
    
}

AbstractEnemyAI *AbstractEnemy::getAI() const
{
    return ai;
}