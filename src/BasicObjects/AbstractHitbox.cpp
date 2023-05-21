#include <BasicObjects/AbstractHitbox.h>
#include <tuple>
#include <QDebug>

AbstractHitbox::AbstractHitbox(QSizeF _size, QPointF _position, GameObject *_parent)
    : GameObject(_position, _parent)
    , size(_size) {}

QSizeF AbstractHitbox::getSize() const
{
    return size;
}

bool AbstractHitbox::intersects(const AbstractHitbox *other) const
{
    QPointF pos1 = getAbsolutePosition();
    QPointF pos2 = other->getAbsolutePosition();
    qreal x11 = pos1.x() - size.width() * 0.5;
    qreal x12 = pos1.x() + size.width() * 0.5;
    qreal y11 = pos1.y() - size.height() * 0.5;
    qreal y12 = pos1.y() + size.height() * 0.5;
    qreal x21 = pos2.x() - other->size.width() * 0.5;
    qreal x22 = pos2.x() + other->size.width() * 0.5;
    qreal y21 = pos2.y() - other->size.height() * 0.5;
    qreal y22 = pos2.y() + other->size.height() * 0.5;
    if(std::max(x11, x21) > std::min(x12, x22))
        return false;
    if(std::max(y11, y21) > std::min(y12, y22))
        return false;
    return true;
}