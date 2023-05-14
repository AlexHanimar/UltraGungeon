#include <Entities/Door.h>

void Door::setActive(bool _nactive)
{
    active = _nactive;
}

bool Door::isActive() const
{
    return active;
}