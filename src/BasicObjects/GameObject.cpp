#include <BasicObjects/GameObject.h>
#include <QDebug>

GameObject::GameObject(QPointF _position, GameObject *_parent)
    : position(_position)
    , parent(_parent)
{
    if(parent != nullptr)
        parent->children.push_back(this);
}

void GameObject::setPosition(QPointF _nposition)
{
    position = _nposition;
}

void GameObject::moveBy(QPointF _dposition)
{
    position += _dposition;
}

QPointF GameObject::getPosition() const
{
    return position;
}

QPointF GameObject::getAbsolutePosition() const
{
    QPointF anchor = (parent != nullptr ? parent->getAbsolutePosition() : QPointF(0, 0));
    return anchor + position;
}

GameObject *GameObject::getParent() const
{
    return parent;
}

std::vector<GameObject *> GameObject::getChildren() const
{
    return children;
}

GameObject::~GameObject() noexcept
{
    for(auto* child : children)
        delete child;
    if(parent != nullptr)
        *std::find(parent->children.begin(), parent->children.end(), this) = nullptr;
}