#pragma once

#include <BasicObjects/AbstractHitbox.h>

class Trigger : public AbstractHitbox {
protected:
    bool triggered;
public:
    using AbstractHitbox::AbstractHitbox;
    [[nodiscard("Trigger::isTriggered() unused")]] bool isTriggered() const;
    void setTriggered(bool _triggered);
};