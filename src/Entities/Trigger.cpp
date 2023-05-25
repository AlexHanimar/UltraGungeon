#include <Entities/Trigger.h>

bool Trigger::isTriggered() const
{
    return triggered;
}

void Trigger::setTriggered(bool _triggered)
{
    triggered = _triggered;
}