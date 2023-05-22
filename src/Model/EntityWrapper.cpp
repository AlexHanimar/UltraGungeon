#include <Model/EntityWrapper.h>
#include <QDebug>

AbstractWrapper::~AbstractWrapper() noexcept {}
AbstractInteraction::~AbstractInteraction() noexcept {}

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
    interact(wrap(first->item), wrap(static_cast<MovableEntity*>(second->item)));
}
void Wall_Interaction::apply(Projectile_Wrapper *second)
{
    auto* wall = first->item;
    auto* proj = second->item;
    if(wall->getCollider()->intersects(proj->getCollider()))
        proj->setState(Projectile::STATE::DESTROYED);
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
    interact(wrap(first->item), wrap(static_cast<MovableEntity*>(second->item)));
}
void Door_Interaction::apply(Projectile_Wrapper *second)
{
    auto* door = first->item;
    auto* proj = second->item;
    if(door->isActive() && door->getCollider()->intersects(proj->getCollider()))
        proj->setState(Projectile::STATE::DESTROYED);
}

void MovableEntity_Interaction::apply(Wall_Wrapper *second) {}
void MovableEntity_Interaction::apply(Door_Wrapper *second) {}
void MovableEntity_Interaction::apply(MovableEntity_Wrapper *second) {}
void MovableEntity_Interaction::apply(PlayerEntity_Wrapper *second) {}
void MovableEntity_Interaction::apply(Projectile_Wrapper *second) {}

void PlayerEntity_Interaction::apply(Wall_Wrapper *second) {}
void PlayerEntity_Interaction::apply(Door_Wrapper *second) {}
void PlayerEntity_Interaction::apply(MovableEntity_Wrapper *second) {}
void PlayerEntity_Interaction::apply(PlayerEntity_Wrapper *second) {}
void PlayerEntity_Interaction::apply(Projectile_Wrapper *second)
{
    if(first->item->getState() == PlayerEntity::STATE::DASHING)
        return;
    if(second->item->getState() == Projectile::STATE::DESTROYED)
        return;
    if(second->item->getTeam() == TEAM::PLAYER)
        return;
    if(first->item->getCollider()->intersects(second->item->getCollider()))
        second->item->setState(Projectile::STATE::DESTROYED);
}

void Projectile_Interaction::apply(Wall_Wrapper *second) {}
void Projectile_Interaction::apply(Door_Wrapper *second) {}
void Projectile_Interaction::apply(MovableEntity_Wrapper *second) {}
void Projectile_Interaction::apply(PlayerEntity_Wrapper *second)
{
    if(second->item->getState() == PlayerEntity::STATE::DASHING)
        return;
    if(first->item->getState() == Projectile::STATE::DESTROYED)
        return;
    if(first->item->getTeam() == TEAM::PLAYER)
        return;
    if(first->item->getCollider()->intersects(second->item->getCollider()))
        second->item->applyDamage(first->item->getDamage());
}
void Projectile_Interaction::apply(Projectile_Wrapper *second) {}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// interaction destructors
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Wall_Interaction::~Wall_Interaction() noexcept {}
Door_Interaction::~Door_Interaction() noexcept {}
MovableEntity_Interaction::~MovableEntity_Interaction() noexcept {}
PlayerEntity_Interaction::~PlayerEntity_Interaction() noexcept {}
Projectile_Interaction::~Projectile_Interaction() noexcept {}
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
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
