#pragma once

#include <BasicObjects/GameObject.h>
#include <BasicObjects/AbstractHitbox.h>

class AbstractEntity : public GameObject {
protected:
    AbstractHitbox* collider;
public:
    explicit AbstractEntity(QSizeF _size, QPointF _position = {0, 0}, GameObject* _parent = nullptr);
    [[nodiscard("AbstractEntity::getCollider() unused")]] virtual AbstractHitbox* getCollider() const;
};