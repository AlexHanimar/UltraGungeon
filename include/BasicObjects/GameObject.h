#pragma once

#include <QPointF>
#include <vector>

class GameObject {
protected:
    GameObject* parent;
    QPointF position;
    std::vector<GameObject*> children;
public:
    explicit GameObject(QPointF _position = {0, 0}, GameObject* _parent = nullptr);
    virtual void setPosition(QPointF _nposition);
    virtual void moveBy(QPointF _dposition);
    [[nodiscard("GameObject::getPosition() unused")]] virtual QPointF getPosition() const;
    [[nodiscard("GameObject::getAbsolutePosition() unused")]] virtual QPointF getAbsolutePosition() const;
    [[nodiscard("GameObject::getParent() unused")]] virtual GameObject* getParent() const;
    [[nodiscard("GameObject::getChildren() unused")]] virtual std::vector<GameObject*> getChildren() const;

    virtual ~GameObject();
};