#include <BasicObjects/AbstractEntity.h>

AbstractEntity::AbstractEntity(QSizeF _size, QPointF _position, GameObject *_parent)
    : GameObject(_position, _parent)
    , collider(new AbstractHitbox(_size, {0, 0}, this)) {}

AbstractHitbox *AbstractEntity::getCollider() const
{
    return collider;
}