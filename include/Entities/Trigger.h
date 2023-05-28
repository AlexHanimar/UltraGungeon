#pragma once

#include <BasicObjects/AbstractHitbox.h>

class Trigger : public AbstractHitbox {
protected:
    bool used;
    int state;
public:
    using AbstractHitbox::AbstractHitbox;
    enum STATE {
        DEFAULT = 0,
        TRIGGERED = 1,
        DISABLED = 2
    };
    [[nodiscard("Trigger::getState() unused")]] virtual int getState() const;
    void setState(int _state);

    [[nodiscard("Trigger::isUsed() unused")]] bool isUsed() const;
    void setUsed(bool _used);
};