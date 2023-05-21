#pragma once

#include <QPointF>
#include <QSizeF>
#include <BasicObjects/GameObject.h>

class AbstractHitbox : public GameObject {
protected:
    QSizeF size;
public:
    AbstractHitbox(QSizeF _size, QPointF _position = {0, 0}, GameObject* _parent = nullptr);
    [[nodiscard("AbstractHitbox::getSize() unused")]] virtual QSizeF getSize() const;
    virtual bool intersects(const AbstractHitbox* other) const;
    virtual ~AbstractHitbox() noexcept = default;
};