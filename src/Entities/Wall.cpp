#include <Entities/Wall.h>

Wall::Wall(QSizeF _size, qreal _horisontalOffset, qreal _verticalOffset, QPointF _position, GameObject *_parent)
    : AbstractEntity(_size, _position, _parent)
    , verticalCollider(new AbstractHitbox({_size.width() - _horisontalOffset, _size.height() + _verticalOffset}, {0, 0}, this))
    , horisontalCollider(new AbstractHitbox({_size.width() + _horisontalOffset, _size.height() - _verticalOffset}, {0, 0}, this)) {}

AbstractHitbox* Wall::getHorisontalCollider() const
{
    return horisontalCollider;
}

AbstractHitbox* Wall::getVerticalCollider() const
{
    return verticalCollider;
}