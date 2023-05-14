#pragma once

#include <Entities/Wall.h>

class Door : public Wall {
protected:
    bool active = false;
public:
    using Wall::Wall;

    virtual void setActive(bool _nactive);
    [[nodiscard("Door::isActive() unused")]] virtual bool isActive() const;

    virtual ~Door() = default;
};