#include <Entities/Trigger.h>

int Trigger::getState() const
{
    return state;
}

void Trigger::setState(int _state)
{
    switch(_state) {
        case Trigger::STATE::DEFAULT:
            state = _state;
            break;
        case Trigger::STATE::TRIGGERED:
            if(state != Trigger::STATE::DEFAULT)
                break;
            state = _state;
            break;
        case Trigger::STATE::DISABLED:
            state = _state;
            break;
        default:
            break;
    }
}

bool Trigger::isUsed() const
{
    return used;
}

void Trigger::setUsed(bool _used)
{
    used = _used;
}

