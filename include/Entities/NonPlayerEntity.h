#pragma once

#include <Entities/MovableEntity.h>

enum class TEAM {
    ENEMY,
    PLAYER,
    NEUTRAL
};

class NonPlayerEntity : public MovableEntity {
protected:
    TEAM team = TEAM::NEUTRAL;
public:
    using MovableEntity::MovableEntity;
    virtual void setTeam(TEAM _team);
    [[nodiscard("NonPlayerEntity::getTeam() unused")]] virtual TEAM getTeam() const;
};