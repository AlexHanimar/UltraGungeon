#pragma once

#include <BasicObjects/AbstractEntity.h>

class Wall : public AbstractEntity {
protected:
    AbstractHitbox* verticalCollider;
    AbstractHitbox* horisontalCollider;
public:
    Wall(QSizeF _size, qreal _horisontalOffset, qreal _verticalOffset, QPointF _position = {0, 0}, GameObject* _parent = nullptr);
    [[nodiscard("Wall::getHorisontalCollider() unused")]] virtual AbstractHitbox* getHorisontalCollider() const;
    [[nodiscard("Wall::getVerticalCollider() unused")]] virtual AbstractHitbox* getVerticalCollider() const;
};