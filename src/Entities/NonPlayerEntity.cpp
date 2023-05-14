#include <Entities/NonPlayerEntity.h>

void NonPlayerEntity::setTeam(TEAM _team)
{
    team = _team;
}

TEAM NonPlayerEntity::getTeam() const
{
    return team;
}