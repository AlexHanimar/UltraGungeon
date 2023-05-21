#pragma once

#include <Entities/MovableEntity.h>

class PlayerEntity : public MovableEntity {
private:
    int state; //
    qreal defaultSpeed; //
    qreal dashSpeed; //

    qreal dashTimer; //
    qreal maxDashTimer; //
    qreal dashRechargeTimer; //
    qreal maxDashRechargeTimer; //

    qreal health; //

    int weapon; //
    std::vector<int> weaponState; //
    std::vector<qreal> reloadTimer; //
    std::vector<qreal> maxReloadTimer; //



    int spawnAction;
    QPointF spawnDirection;
public:
    enum STATE {
        DEFAULT = 0,
        DASHING = 1,
        DASH_RECHARGE = 2
    };
    enum WEAPON {
        PISTOL = 0,
        SHOTGUN = 1,
        RAILGUN = 2
    };
    enum WEAPON_STATE {
        READY = 0,
        RELOADING = 1
    };
    enum SPAWN_ACTION {
        NONE = 100000,
        PISTOL_1 = 0,
        PISTOL_2 = 1,
        SHOTGUN_1 = 2,
        SHOTGUN_2 = 3,
        RAILGUN_1 = 4,
        RAILGUN_2 = 5
    };
    using MovableEntity::MovableEntity;
    void setState(int _state);
    [[nodiscard("PlayerEntity::getState() unused")]] int getState() const;
    void update(qreal deltaT) override;
    void setHealth(int _health);
    void applyDamage(qreal damage);
    [[nodiscard("PlayerEntity::getHealth() unused")]] qreal getHealth() const;

    void setWeapon(int _weapon);
    [[nodiscard("PlayerEntity::getWeapon() unused")]] int getWeapon() const;

    void setWeaponState(int _state);
    [[nodiscard("PlayerEntity::getWeaponState() unused")]] int getWeaponState() const;

    void setSpawnAction(int _spawnAction);
    [[nodiscard("PlayerEntity::getSpawnAction() unused")]] int getSpawnAction() const;

    void setSpawnDirection(QPointF _spawnDirection);
    [[nodiscard("PlayerEntity::getSpawnDirection() unused")]] QPointF getSpawnDirection() const;

    void init();
};