#include <Model/EntityWrapper.h>
#include <QDebug>

AbstractWrapper::~AbstractWrapper() = default;
AbstractInteraction::~AbstractInteraction() = default;

// generating interactions
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractInteraction *Wall_Wrapper::generateInteraction()
{
    auto* inter = new Wall_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *Door_Wrapper::generateInteraction()
{
    auto* inter = new Door_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *MovableEntity_Wrapper::generateInteraction()
{
    auto* inter = new MovableEntity_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *PlayerEntity_Wrapper::generateInteraction()
{
    auto* inter = new PlayerEntity_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *Projectile_Wrapper::generateInteraction()
{
    auto* inter = new Projectile_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *EnemyFilth_Wrapper::generateInteraction()
{
    auto* inter = new EnemyFilth_Interaction;
    inter->first = this;
    return inter;
}

AbstractInteraction *EnemyAndre_Wrapper::generateInteraction()
{
    auto* inter = new EnemyAndre_Interaction;
    inter->first = this;
    return inter;
}

AbstractInteraction *Trigger_Wrapper::generateInteraction()
{
    auto* inter = new Trigger_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *Hitscan_Wrapper::generateInteraction()
{
    auto* inter = new Hitscan_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *PistolHitscan_Wrapper::generateInteraction()
{
    auto* inter = new PistolHitscan_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *BlueRailgunHitscan_Wrapper::generateInteraction()
{
    auto* inter = new BlueRailgunHitscan_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction* AndreBallProjectile_Wrapper::generateInteraction()
{
    auto* inter = new AndreBallProjectile_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *ParryProjectile_Wrapper::generateInteraction()
{
    auto* inter = new ParryProjectile_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *ShotgunPelletProjectile_Wrapper::generateInteraction()
{
    auto* inter = new ShotgunPelletProjectile_Interaction;
    inter->first = this;
    return inter;
}

AbstractInteraction *Explosion_Wrapper::generateInteraction()
{
    auto* inter = new Explosion_Interaction;
    inter->first = this;
    return inter;
}
AbstractInteraction *Coin_Wrapper::generateInteraction()
{
    auto* inter = new Coin_Interaction;
    inter->first = this;
    return inter;
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// accepting interactions
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Wall_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void Door_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void MovableEntity_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void PlayerEntity_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void Projectile_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void EnemyFilth_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void EnemyAndre_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void Trigger_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void Hitscan_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void PistolHitscan_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void BlueRailgunHitscan_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void AndreBallProjectile_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void ParryProjectile_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void ShotgunPelletProjectile_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void Explosion_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
void Coin_Wrapper::accept(AbstractInteraction *interaction)
{
    interaction->apply(this);
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// applying interactions
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Wall_Interaction::apply(Wall_Wrapper *second) {}
void Wall_Interaction::apply(Door_Wrapper *second) {}
void Wall_Interaction::apply(MovableEntity_Wrapper *second)
{
    auto* wall = this->first->item;
    auto* entity = second->item;
    QPointF wallPos = wall->getAbsolutePosition();
    QPointF entityPos = entity->getAbsolutePosition();
    QPointF velocity = entity->getVelocity();
    // update velocity
    if(wall->getHorisontalCollider()->intersects(entity->getCollider())) {
        if(entityPos.x() >= wallPos.x())
            velocity.rx() = std::max(0.0, velocity.x());
        if(entityPos.x() <= wallPos.x())
            velocity.rx() = std::min(0.0, velocity.x());
    }
    if(wall->getVerticalCollider()->intersects(entity->getCollider())) {
        if(entityPos.y() >= wallPos.y())
            velocity.ry() = std::max(0.0, velocity.y());
        if(entityPos.y() <= wallPos.y())
            velocity.ry() = std::min(0.0, velocity.y());
    }
    entity->setVelocity(velocity);
}
void Wall_Interaction::apply(PlayerEntity_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<MovableEntity*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Wall_Interaction::apply(Projectile_Wrapper *second)
{
    auto* wall = first->item;
    auto* proj = second->item;
    if(wall->getCollider()->intersects(proj->getCollider()))
        proj->setState(Projectile::STATE::DESTROYED);
}
void Wall_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<MovableEntity*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Wall_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<MovableEntity*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Wall_Interaction::apply(Trigger_Wrapper *second) {}
void Wall_Interaction::apply(Hitscan_Wrapper *second) {}
void Wall_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Wall_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void Wall_Interaction::apply(AndreBallProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Wall_Interaction::apply(ParryProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Wall_Interaction::apply(ShotgunPelletProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Wall_Interaction::apply(Explosion_Wrapper *second) {}
void Wall_Interaction::apply(Coin_Wrapper *second)
{
    if(first->item->getCollider()->intersects(second->item->getCollider()))
        second->item->setState(Coin::STATE::DESTROYED);
}

void Door_Interaction::apply(Wall_Wrapper *second) {}
void Door_Interaction::apply(Door_Wrapper *second) {}
void Door_Interaction::apply(MovableEntity_Wrapper *second)
{
    auto* door = this->first->item;
    auto* entity = second->item;
    QPointF doorPos = door->getAbsolutePosition();
    QPointF entityPos = entity->getAbsolutePosition();
    QPointF velocity = entity->getVelocity();
    // update velocity
    if(!door->isActive())
        return;
    if(door->getHorisontalCollider()->intersects(entity->getCollider())) {
        if(entityPos.x() >= doorPos.x())
            velocity.rx() = std::max(0.0, velocity.x());
        if(entityPos.x() <= doorPos.x())
            velocity.rx() = std::min(0.0, velocity.x());
    }
    if(door->getVerticalCollider()->intersects(entity->getCollider())) {
        if(entityPos.y() >= doorPos.y())
            velocity.ry() = std::max(0.0, velocity.y());
        if(entityPos.y() <= doorPos.y())
            velocity.ry() = std::min(0.0, velocity.y());
    }
    entity->setVelocity(velocity);
}
void Door_Interaction::apply(PlayerEntity_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<MovableEntity*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Door_Interaction::apply(Projectile_Wrapper *second)
{
    auto* door = first->item;
    auto* proj = second->item;
    if(door->isActive() && door->getCollider()->intersects(proj->getCollider()))
        proj->setState(Projectile::STATE::DESTROYED);
}
void Door_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<MovableEntity*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Door_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<MovableEntity*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Door_Interaction::apply(Trigger_Wrapper *second) {}
void Door_Interaction::apply(Hitscan_Wrapper *second) {}
void Door_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Door_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void Door_Interaction::apply(AndreBallProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Door_Interaction::apply(ParryProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Door_Interaction::apply(ShotgunPelletProjectile_Wrapper*second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Door_Interaction::apply(Explosion_Wrapper *second) {}
void Door_Interaction::apply(Coin_Wrapper *second)
{
    if(first->item->isActive() && first->item->getCollider()->intersects(second->item->getCollider()))
        second->item->setState(Coin::STATE::DESTROYED);
}

void MovableEntity_Interaction::apply(Wall_Wrapper *second) {}
void MovableEntity_Interaction::apply(Door_Wrapper *second) {}
void MovableEntity_Interaction::apply(MovableEntity_Wrapper *second) {}
void MovableEntity_Interaction::apply(PlayerEntity_Wrapper *second) {}
void MovableEntity_Interaction::apply(Projectile_Wrapper *second) {}
void MovableEntity_Interaction::apply(EnemyFilth_Wrapper *second) {}
void MovableEntity_Interaction::apply(EnemyAndre_Wrapper *second) {}
void MovableEntity_Interaction::apply(Trigger_Wrapper *second) {}
void MovableEntity_Interaction::apply(Hitscan_Wrapper *second) {}
void MovableEntity_Interaction::apply(PistolHitscan_Wrapper *second) {}
void MovableEntity_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void MovableEntity_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void MovableEntity_Interaction::apply(ParryProjectile_Wrapper *second) {}
void MovableEntity_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void MovableEntity_Interaction::apply(Explosion_Wrapper *second) {}
void MovableEntity_Interaction::apply(Coin_Wrapper *second) {}

void PlayerEntity_Interaction::apply(Wall_Wrapper *second) {}
void PlayerEntity_Interaction::apply(Door_Wrapper *second) {}
void PlayerEntity_Interaction::apply(MovableEntity_Wrapper *second) {}
void PlayerEntity_Interaction::apply(PlayerEntity_Wrapper *second) {}
void PlayerEntity_Interaction::apply(Projectile_Wrapper *second) {}
void PlayerEntity_Interaction::apply(EnemyFilth_Wrapper *second)
{
    second->item->setDestination(first->item->getAbsolutePosition());
}
void PlayerEntity_Interaction::apply(EnemyAndre_Wrapper *second)
{
    second->item->setDestination(first->item->getAbsolutePosition());
}
void PlayerEntity_Interaction::apply(Trigger_Wrapper *second) {}
void PlayerEntity_Interaction::apply(Hitscan_Wrapper *second) {}
void PlayerEntity_Interaction::apply(PistolHitscan_Wrapper *second) {}
void PlayerEntity_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void PlayerEntity_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void PlayerEntity_Interaction::apply(ParryProjectile_Wrapper *second) {}
void PlayerEntity_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void PlayerEntity_Interaction::apply(Explosion_Wrapper *second) {}
void PlayerEntity_Interaction::apply(Coin_Wrapper *second) {}

void Projectile_Interaction::apply(Wall_Wrapper *second) {}
void Projectile_Interaction::apply(Door_Wrapper *second) {}
void Projectile_Interaction::apply(MovableEntity_Wrapper *second) {}
void Projectile_Interaction::apply(PlayerEntity_Wrapper *second)
{
    if(second->item->getParryState() == PlayerEntity::PARRY_STATE::PARRY_ACTIVE
    && second->item->getParryHitbox()->intersects(first->item->getCollider())) {
        second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::PARRY);
        first->item->setState(Projectile::STATE::DESTROYED);
        second->item->setParryState(PlayerEntity::PARRY_STATE::PARRY_RECOVERY);
    }
    if(second->item->getState() == PlayerEntity::STATE::DASHING)
        return;
    if(first->item->getState() == Projectile::STATE::DESTROYED)
        return;
    if(first->item->getTeam() == TEAM::PLAYER)
        return;
    if(first->item->getCollider()->intersects(second->item->getCollider())) {
        second->item->applyDamage(first->item->getDamage());
        first->item->setState(Projectile::STATE::DESTROYED);
    }
}
void Projectile_Interaction::apply(Projectile_Wrapper *second) {}
void Projectile_Interaction::apply(EnemyFilth_Wrapper *second)
{
    if(first->item->getTeam() == TEAM::ENEMY)
        return;
    if(first->item->getState() == Projectile::STATE::DESTROYED)
        return;
    if(first->item->getCollider()->intersects(second->item->getCollider())) {
        second->item->applyDamage(first->item->getDamage());
        first->item->setState(Projectile::STATE::DESTROYED);
    }
}
void Projectile_Interaction::apply(EnemyAndre_Wrapper *second)
{
    if(first->item->getTeam() == TEAM::ENEMY)
        return;
    if(first->item->getState() == Projectile::STATE::DESTROYED)
        return;
    if(first->item->getCollider()->intersects(second->item->getCollider())) {
        second->item->applyDamage(first->item->getDamage());
        first->item->setState(Projectile::STATE::DESTROYED);
    }
}
void Projectile_Interaction::apply(Trigger_Wrapper *second) {}
void Projectile_Interaction::apply(Hitscan_Wrapper *second) {}
void Projectile_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Projectile_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void Projectile_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void Projectile_Interaction::apply(ParryProjectile_Wrapper *second) {}
void Projectile_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void Projectile_Interaction::apply(Explosion_Wrapper *second) {}
void Projectile_Interaction::apply(Coin_Wrapper *second) {}

void EnemyFilth_Interaction::apply(Wall_Wrapper *second) {}
void EnemyFilth_Interaction::apply(Door_Wrapper *second) {}
void EnemyFilth_Interaction::apply(MovableEntity_Wrapper *second) {}
void EnemyFilth_Interaction::apply(PlayerEntity_Wrapper *second)
{
    if(second->item->getState() == PlayerEntity::STATE::DASHING)
        return;
    if(first->item->hitboxIsActive() && first->item->getCollider()->intersects(second->item->getCollider())) {
        second->item->applyDamage(first->item->getDamage());
        first->item->setHitboxActive(false);
    }
}
void EnemyFilth_Interaction::apply(Projectile_Wrapper *second) {}
void EnemyFilth_Interaction::apply(EnemyFilth_Wrapper *second)
{
    if(first == second)
        return;
    if(!first->item->getCollider()->intersects(second->item->getCollider()))
        return;
    if(second->item->getState() == EnemyFilth::STATE::DASHING)
        return;
    auto dir = normalize(second->item->getAbsolutePosition() - first->item->getAbsolutePosition());
    auto speed = second->item->getMaxSpeed();
    second->item->setVelocity(second->item->getVelocity() + dir * speed);

}
void EnemyFilth_Interaction::apply(EnemyAndre_Wrapper *second) {}
void EnemyFilth_Interaction::apply(Trigger_Wrapper *second) {}
void EnemyFilth_Interaction::apply(Hitscan_Wrapper *second) {}
void EnemyFilth_Interaction::apply(PistolHitscan_Wrapper *second) {}
void EnemyFilth_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void EnemyFilth_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void EnemyFilth_Interaction::apply(ParryProjectile_Wrapper *second) {}
void EnemyFilth_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void EnemyFilth_Interaction::apply(Explosion_Wrapper *second) {}
void EnemyFilth_Interaction::apply(Coin_Wrapper *second) {}

void EnemyAndre_Interaction::apply(Wall_Wrapper *second) {}
void EnemyAndre_Interaction::apply(Door_Wrapper *second) {}
void EnemyAndre_Interaction::apply(MovableEntity_Wrapper *second) {}
void EnemyAndre_Interaction::apply(PlayerEntity_Wrapper *second)
{
    if(second->item->getState() == PlayerEntity::STATE::DASHING)
        return;
    if(first->item->hitboxIsActive() && first->item->getCollider()->intersects(second->item->getCollider())) {
        second->item->applyDamage(first->item->getDamage());
        first->item->setHitboxActive(false);
    }
}
void EnemyAndre_Interaction::apply(Projectile_Wrapper *second) {}
void EnemyAndre_Interaction::apply(EnemyFilth_Wrapper *second) {}
void EnemyAndre_Interaction::apply(EnemyAndre_Wrapper *second)
{
    if(first == second)
        return;
    if(!first->item->getCollider()->intersects(second->item->getCollider()))
        return;
    if(second->item->getState() == EnemyAndre::STATE::DASHING)
        return;
    auto dir = normalize(second->item->getAbsolutePosition() - first->item->getAbsolutePosition());
    auto speed = second->item->getMaxSpeed();
    second->item->setVelocity(second->item->getVelocity() + dir * speed);
}
void EnemyAndre_Interaction::apply(Trigger_Wrapper *second) {}
void EnemyAndre_Interaction::apply(Hitscan_Wrapper *second) {}
void EnemyAndre_Interaction::apply(PistolHitscan_Wrapper *second) {}
void EnemyAndre_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void EnemyAndre_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void EnemyAndre_Interaction::apply(ParryProjectile_Wrapper *second) {}
void EnemyAndre_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void EnemyAndre_Interaction::apply(Explosion_Wrapper *second) {}
void EnemyAndre_Interaction::apply(Coin_Wrapper *second) {}

void Trigger_Interaction::apply(Wall_Wrapper *second) {}
void Trigger_Interaction::apply(Door_Wrapper *second) {}
void Trigger_Interaction::apply(MovableEntity_Wrapper *second) {}
void Trigger_Interaction::apply(PlayerEntity_Wrapper *second)
{
    if(first->item->intersects(second->item->getCollider()))
        first->item->setState(Trigger::STATE::TRIGGERED);
}
void Trigger_Interaction::apply(Projectile_Wrapper *second) {}
void Trigger_Interaction::apply(EnemyFilth_Wrapper *second) {}
void Trigger_Interaction::apply(EnemyAndre_Wrapper *second) {}
void Trigger_Interaction::apply(Trigger_Wrapper *second) {}
void Trigger_Interaction::apply(Hitscan_Wrapper *second) {}
void Trigger_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Trigger_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void Trigger_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void Trigger_Interaction::apply(ParryProjectile_Wrapper *second) {}
void Trigger_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void Trigger_Interaction::apply(Explosion_Wrapper *second) {}
void Trigger_Interaction::apply(Coin_Wrapper *second) {}

void Hitscan_Interaction::apply(Wall_Wrapper *second)
{
    if(first->item->getState() == Hitscan::STATE::CHARGED)
        first->item->addPierce(second->item->getCollider());
}
void Hitscan_Interaction::apply(Door_Wrapper *second)
{
    if(first->item->getState() == Hitscan::STATE::CHARGED && second->item->isActive())
        first->item->addPierce(second->item->getCollider());
}
void Hitscan_Interaction::apply(MovableEntity_Wrapper *second) {}
void Hitscan_Interaction::apply(PlayerEntity_Wrapper *second) {}
void Hitscan_Interaction::apply(Projectile_Wrapper *second) {}
void Hitscan_Interaction::apply(EnemyFilth_Wrapper *second)
{
    if(first->item->getState() == Hitscan::STATE::CHARGED)
        first->item->addPierce(second->item->getCollider());
    if(first->item->getState() == Hitscan::STATE::DEFAULT && first->item->pierces(second->item->getCollider()))
        second->item->applyDamage(first->item->getDamage());
}
void Hitscan_Interaction::apply(EnemyAndre_Wrapper *second)
{
    if(first->item->getState() == Hitscan::STATE::CHARGED)
        first->item->addPierce(second->item->getCollider());
    if(first->item->getState() == Hitscan::STATE::DEFAULT && first->item->pierces(second->item->getCollider()))
        second->item->applyDamage(first->item->getDamage());
}
void Hitscan_Interaction::apply(Trigger_Wrapper *second) {}
void Hitscan_Interaction::apply(Hitscan_Wrapper *second)
{
    if(first != second)
        return;
    switch(second->item->getState()) {
        case Hitscan::STATE::CHARGED:
            second->item->setState(Hitscan::STATE::DEFAULT);
            break;
        case Hitscan::STATE::DEFAULT:
            second->item->setState(Hitscan::STATE::DISCHARGED);
            break;
        default:
            break;
    }
}
void Hitscan_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Hitscan_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void Hitscan_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void Hitscan_Interaction::apply(ParryProjectile_Wrapper *second) {}
void Hitscan_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void Hitscan_Interaction::apply(Explosion_Wrapper *second) {}
void Hitscan_Interaction::apply(Coin_Wrapper *second) {}

void PistolHitscan_Interaction::apply(Wall_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void PistolHitscan_Interaction::apply(Door_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void PistolHitscan_Interaction::apply(MovableEntity_Wrapper *second) {}
void PistolHitscan_Interaction::apply(PlayerEntity_Wrapper *second) {}
void PistolHitscan_Interaction::apply(Projectile_Wrapper *second) {}
void PistolHitscan_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void PistolHitscan_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void PistolHitscan_Interaction::apply(Trigger_Wrapper *second) {}
void PistolHitscan_Interaction::apply(Hitscan_Wrapper *second) {}
void PistolHitscan_Interaction::apply(PistolHitscan_Wrapper *second)
{
    if(first != second)
        return;
    switch(second->item->getState()) {
        case Hitscan::STATE::CHARGED:
            second->item->setState(Hitscan::STATE::DEFAULT);
            break;
        case Hitscan::STATE::DEFAULT:
            second->item->setState(Hitscan::STATE::DISCHARGED);
            break;
        default:
            break;
    }
}
void PistolHitscan_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void PistolHitscan_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void PistolHitscan_Interaction::apply(ParryProjectile_Wrapper *second) {}
void PistolHitscan_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void PistolHitscan_Interaction::apply(Explosion_Wrapper *second) {}
void PistolHitscan_Interaction::apply(Coin_Wrapper *second)
{
    if(first->item->getState() == Hitscan::STATE::CHARGED && second->item->getState() == Coin::STATE::ACTIVE)
        first->item->addPierce(second->item->getCollider());
    if(first->item->getState() == Hitscan::STATE::DEFAULT
    && first->item->pierces(second->item->getCollider())
    && second->item->getState() == Coin::STATE::ACTIVE) {
        second->item->setState(Coin::STATE::DEADCOIN);
        second->item->setSpawnAction(Coin::SPAWN_ACTION::PISTOL);
    }
}

void BlueRailgunHitscan_Interaction::apply(Wall_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void BlueRailgunHitscan_Interaction::apply(Door_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void BlueRailgunHitscan_Interaction::apply(MovableEntity_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(PlayerEntity_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(Projectile_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void BlueRailgunHitscan_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Hitscan*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void BlueRailgunHitscan_Interaction::apply(Trigger_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(Hitscan_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(PistolHitscan_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(BlueRailgunHitscan_Wrapper *second)
{
    if(first != second)
        return;
    switch(second->item->getState()) {
        case Hitscan::STATE::CHARGED:
            second->item->setState(Hitscan::STATE::DEFAULT);
            break;
        case Hitscan::STATE::DEFAULT:
            second->item->setState(Hitscan::STATE::DISCHARGED);
            break;
        default:
            break;
    }
}
void BlueRailgunHitscan_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(ParryProjectile_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(Explosion_Wrapper *second) {}
void BlueRailgunHitscan_Interaction::apply(Coin_Wrapper *second)
{
    if(first->item->getState() == Hitscan::STATE::CHARGED && second->item->getState() == Coin::STATE::ACTIVE)
        first->item->addPierce(second->item->getCollider());
    if(first->item->getState() == Hitscan::STATE::DEFAULT
       && first->item->pierces(second->item->getCollider())
       && second->item->getState() == Coin::STATE::ACTIVE) {
        second->item->setState(Coin::STATE::DEADCOIN);
        second->item->setSpawnAction(Coin::SPAWN_ACTION::RAILGUN);
    }
}

void AndreBallProjectile_Interaction::apply(Wall_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(Door_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(MovableEntity_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(PlayerEntity_Wrapper *second)
{
    if(second->item->getParryState() == PlayerEntity::PARRY_STATE::PARRY_ACTIVE
       && second->item->getParryHitbox()->intersects(first->item->getCollider())) {
        second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::NONE);
        first->item->setDirection(second->item->getSpawnDirection());
        first->item->setTeam(TEAM::PLAYER);
        second->item->setParryState(PlayerEntity::PARRY_STATE::PARRY_RECOVERY);
    }
    if(second->item->getState() == PlayerEntity::STATE::DASHING)
        return;
    if(first->item->getState() == AndreBallProjectile::STATE::DESTROYED)
        return;
    if(first->item->getCollider()->intersects(second->item->getCollider())) {
        second->item->applyDamage(first->item->getDamage());
        first->item->setState(AndreBallProjectile::STATE::DESTROYED);
    }
}
void AndreBallProjectile_Interaction::apply(Projectile_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void AndreBallProjectile_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void AndreBallProjectile_Interaction::apply(Trigger_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(Hitscan_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(PistolHitscan_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(ParryProjectile_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(Explosion_Wrapper *second) {}
void AndreBallProjectile_Interaction::apply(Coin_Wrapper *second) {}

void ParryProjectile_Interaction::apply(Wall_Wrapper *second) {}
void ParryProjectile_Interaction::apply(Door_Wrapper *second) {}
void ParryProjectile_Interaction::apply(MovableEntity_Wrapper *second) {}
void ParryProjectile_Interaction::apply(PlayerEntity_Wrapper *second) {}
void ParryProjectile_Interaction::apply(Projectile_Wrapper *second) {}
void ParryProjectile_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void ParryProjectile_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void ParryProjectile_Interaction::apply(Trigger_Wrapper *second) {}
void ParryProjectile_Interaction::apply(Hitscan_Wrapper *second) {}
void ParryProjectile_Interaction::apply(PistolHitscan_Wrapper *second) {}
void ParryProjectile_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void ParryProjectile_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void ParryProjectile_Interaction::apply(ParryProjectile_Wrapper *second) {}
void ParryProjectile_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void ParryProjectile_Interaction::apply(Explosion_Wrapper *second) {}
void ParryProjectile_Interaction::apply(Coin_Wrapper *second) {}

void ShotgunPelletProjectile_Interaction::apply(Wall_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(Door_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(MovableEntity_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(PlayerEntity_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void ShotgunPelletProjectile_Interaction::apply(Projectile_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void ShotgunPelletProjectile_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(first->item));
    interact(wrapper, second);
    delete wrapper;
}
void ShotgunPelletProjectile_Interaction::apply(Trigger_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(Hitscan_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(PistolHitscan_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(ParryProjectile_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(Explosion_Wrapper *second) {}
void ShotgunPelletProjectile_Interaction::apply(Coin_Wrapper *second) {}

void Explosion_Interaction::apply(Wall_Wrapper *second) {}
void Explosion_Interaction::apply(Door_Wrapper *second) {}
void Explosion_Interaction::apply(MovableEntity_Wrapper *second) {}
void Explosion_Interaction::apply(PlayerEntity_Wrapper *second)
{
    if(second->item->getState() == PlayerEntity::STATE::DASHING)
        return;
    if(first->item->getState() == Explosion::STATE::DEFAULT && first->item->overlapsWith(second->item))
        second->item->applyDamage(first->item->getDamage());
}
void Explosion_Interaction::apply(Projectile_Wrapper *second)
{
    if(first->item->getState() == Explosion::STATE::DEFAULT && first->item->overlapsWith(second->item)) {
        auto v = second->item->getAbsolutePosition() - first->item->getAbsolutePosition();
        v = normalize(v);
        v *= second->item->getSpeed();
        second->item->setTeam(TEAM::NEUTRAL);
        second->item->setVelocity(v);
    }
}
void Explosion_Interaction::apply(EnemyFilth_Wrapper *second)
{
    if(first->item->getState() == Explosion::STATE::DEFAULT && first->item->overlapsWith(second->item))
        second->item->applyDamage(first->item->getDamage());
}
void Explosion_Interaction::apply(EnemyAndre_Wrapper *second)
{
    if(first->item->getState() == Explosion::STATE::DEFAULT && first->item->overlapsWith(second->item))
        second->item->applyDamage(first->item->getDamage());
}
void Explosion_Interaction::apply(Trigger_Wrapper *second) {}
void Explosion_Interaction::apply(Hitscan_Wrapper *second) {}
void Explosion_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Explosion_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void Explosion_Interaction::apply(AndreBallProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Explosion_Interaction::apply(ParryProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Explosion_Interaction::apply(ShotgunPelletProjectile_Wrapper *second)
{
    auto* wrapper = wrap(static_cast<Projectile*>(second->item));
    interact(first, wrapper);
    delete wrapper;
}
void Explosion_Interaction::apply(Explosion_Wrapper *second)
{
    if(first == second && first->item->getState() == Explosion::STATE::DEFAULT) {
        first->item->setState(Explosion::STATE::INACTIVE);
    }
}
void Explosion_Interaction::apply(Coin_Wrapper *second) {}

void Coin_Interaction::apply(Wall_Wrapper *second) {}
void Coin_Interaction::apply(Door_Wrapper *second) {}
void Coin_Interaction::apply(MovableEntity_Wrapper *second) {}
void Coin_Interaction::apply(PlayerEntity_Wrapper *second) {}
void Coin_Interaction::apply(Projectile_Wrapper *second) {}
void Coin_Interaction::apply(EnemyFilth_Wrapper *second)
{
    if(first->item->getState() == Coin::STATE::DEADCOIN)
        first->item->addTarget(second->item, 10);
}
void Coin_Interaction::apply(EnemyAndre_Wrapper *second)
{
    if(first->item->getState() == Coin::STATE::DEADCOIN)
        first->item->addTarget(second->item, 10);
}
void Coin_Interaction::apply(Trigger_Wrapper *second) {}
void Coin_Interaction::apply(Hitscan_Wrapper *second) {}
void Coin_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Coin_Interaction::apply(BlueRailgunHitscan_Wrapper *second) {}
void Coin_Interaction::apply(AndreBallProjectile_Wrapper *second) {}
void Coin_Interaction::apply(ParryProjectile_Wrapper *second) {}
void Coin_Interaction::apply(ShotgunPelletProjectile_Wrapper *second) {}
void Coin_Interaction::apply(Explosion_Wrapper *second) {}
void Coin_Interaction::apply(Coin_Wrapper *second)
{
    if(first == second) {
        if(first->item->getState() == Coin::STATE::DEADCOIN)
            first->item->makeTargetList();
    }
    else {
        if(first->item->getState() == Coin::STATE::DEADCOIN && second->item->getState() == Coin::STATE::ACTIVE) {
            first->item->addTarget(second->item, 0);
        }
    }
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// interaction destructors
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Wall_Interaction::~Wall_Interaction() = default;
Door_Interaction::~Door_Interaction() = default;
MovableEntity_Interaction::~MovableEntity_Interaction() = default;
PlayerEntity_Interaction::~PlayerEntity_Interaction() = default;
Projectile_Interaction::~Projectile_Interaction() = default;
EnemyFilth_Interaction::~EnemyFilth_Interaction() = default;
EnemyAndre_Interaction::~EnemyAndre_Interaction() = default;
Trigger_Interaction::~Trigger_Interaction() = default;
Hitscan_Interaction::~Hitscan_Interaction() = default;
PistolHitscan_Interaction::~PistolHitscan_Interaction() = default;
BlueRailgunHitscan_Interaction::~BlueRailgunHitscan_Interaction() = default;
AndreBallProjectile_Interaction::~AndreBallProjectile_Interaction() = default;
ParryProjectile_Interaction::~ParryProjectile_Interaction() = default;
ShotgunPelletProjectile_Interaction::~ShotgunPelletProjectile_Interaction() = default;
Explosion_Interaction::~Explosion_Interaction() = default;
Coin_Interaction::~Coin_Interaction() = default;
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


// general interaction function
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void interact(AbstractWrapper* a, AbstractWrapper* b)
{
    auto* inter = a->generateInteraction();
    b->accept(inter);
    delete inter;
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// generating Wrappers
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractWrapper* wrap(Wall* item) {auto wrapper = new Wall_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(Door* item) {auto wrapper = new Door_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(MovableEntity* item) {auto wrapper = new MovableEntity_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(PlayerEntity* item) {auto wrapper = new PlayerEntity_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(Projectile* item) {auto wrapper = new Projectile_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(EnemyFilth* item) {auto wrapper = new EnemyFilth_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(EnemyAndre* item) {auto wrapper = new EnemyAndre_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(Trigger* item) {auto wrapper = new Trigger_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(Hitscan* item) {auto wrapper = new Hitscan_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(PistolHitscan* item) {auto wrapper = new PistolHitscan_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(BlueRailgunHitscan* item) {auto wrapper = new BlueRailgunHitscan_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(AndreBallProjectile* item) {auto wrapper = new AndreBallProjectile_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(ParryProjectile* item) {auto wrapper = new ParryProjectile_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(ShotgunPelletProjectile* item) {auto wrapper = new ShotgunPelletProjectile_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(Explosion* item) {auto wrapper = new Explosion_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(Coin* item) {auto wrapper = new Coin_Wrapper; wrapper->item = item; return wrapper;}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
