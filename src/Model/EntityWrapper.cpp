#include <Model/EntityWrapper.h>
#include <QDebug>

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

AbstractInteraction *Time_Wrapper::generateInteraction()
{
    auto* inter = new Time_Interaction;
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

void Time_Wrapper::accept(AbstractInteraction *interaction) {}
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

void MovableEntity_Interaction::apply(Wall_Wrapper *second) {}
void MovableEntity_Interaction::apply(Door_Wrapper *second) {}
void MovableEntity_Interaction::apply(MovableEntity_Wrapper *second) {}

void Time_Interaction::apply(Wall_Wrapper *second) {}
void Time_Interaction::apply(Door_Wrapper *second) {}
void Time_Interaction::apply(MovableEntity_Wrapper *second)
{
    second->item->update(*first->item);
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// general interaction function
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void interact(AbstractWrapper* a, AbstractWrapper* b)
{
    auto inter = a->generateInteraction();
    b->accept(inter);
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// generating Wrappers
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractWrapper* wrap(Wall* item) {auto wrapper = new Wall_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(Door* item) {auto wrapper = new Door_Wrapper; wrapper->item = item; return wrapper;}
AbstractWrapper* wrap(MovableEntity* item) {auto wrapper = new MovableEntity_Wrapper; wrapper->item = item; return wrapper;}

AbstractWrapper* wrap(qreal *timeItem) {auto wrapper = new Time_Wrapper; wrapper->item = timeItem; return wrapper;}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
