#include <Entities/PlayerEntity.h>
#include <QDebug>
#include <Helpers/Helpers.h>

int PlayerEntity::getState() const
{
    return state;
}

void PlayerEntity::setHealth(int _health)
{
    health = _health;
}

qreal PlayerEntity::getHealth() const
{
    return health;
}

void PlayerEntity::applyDamage(qreal damage)
{
    health -= damage;
}

void PlayerEntity::setWeapon(int _weapon)
{
    weapon = _weapon;
}

int PlayerEntity::getWeapon() const
{
    return weapon;
}

int PlayerEntity::getWeaponState() const
{
    return weaponState[weapon];
}

void PlayerEntity::setWeaponState(int _state)
{
    switch(_state) {
        case PlayerEntity::WEAPON_STATE::READY:
            weaponState[weapon] = PlayerEntity::WEAPON_STATE::READY;
            break;
        case PlayerEntity::WEAPON_STATE::RELOADING:
            if(weaponState[weapon] != PlayerEntity::WEAPON_STATE::RELOADING) {
                reloadTimer[weapon] = maxReloadTimer[weapon];
                weaponState[weapon] = PlayerEntity::WEAPON_STATE::RELOADING;
            }
            break;
        default:
            break;
    }
}

int PlayerEntity::getSpawnAction() const
{
    return spawnAction;
}

void PlayerEntity::setSpawnAction(int _spawnAction)
{
    switch(_spawnAction) {
        case PlayerEntity::SPAWN_ACTION::PISTOL_1:
            spawnAction = PlayerEntity::SPAWN_ACTION::PISTOL_1;
            break;
        case PlayerEntity::SPAWN_ACTION::PISTOL_2:
            spawnAction = PlayerEntity::SPAWN_ACTION::PISTOL_2;
            break;
        case PlayerEntity::SPAWN_ACTION::SHOTGUN_1:
            spawnAction = PlayerEntity::SPAWN_ACTION::SHOTGUN_1;
            break;
        case PlayerEntity::SPAWN_ACTION::SHOTGUN_2:
            spawnAction = PlayerEntity::SPAWN_ACTION::SHOTGUN_2;
            break;
        case PlayerEntity::SPAWN_ACTION::RAILGUN_1:
            spawnAction = PlayerEntity::SPAWN_ACTION::RAILGUN_1;
            break;
        case PlayerEntity::SPAWN_ACTION::RAILGUN_2:
            spawnAction = PlayerEntity::SPAWN_ACTION::RAILGUN_2;
            break;
        case PlayerEntity::SPAWN_ACTION::PARRY:
            spawnAction = PlayerEntity::SPAWN_ACTION::PARRY;
            break;
        case PlayerEntity::SPAWN_ACTION::NONE:
            spawnAction = PlayerEntity::SPAWN_ACTION::NONE;
            break;
        default:
            break;
    }
}

void PlayerEntity::setState(int _state)
{
    switch(_state) {
        case PlayerEntity::STATE::DEFAULT:
            setMaxSpeed(defaultSpeed);
            state = PlayerEntity::STATE::DEFAULT;
            break;
        case PlayerEntity::STATE::DASHING:
            if(state != PlayerEntity::STATE::DASHING) {
                dashTimer = maxDashTimer;
                setMaxSpeed(dashSpeed);
                state = PlayerEntity::STATE::DASHING;
            }
            break;
        case PlayerEntity::STATE::DASH_RECHARGE:
            if(state != PlayerEntity::STATE::DASH_RECHARGE) {
                dashRechargeTimer = maxDashRechargeTimer;
                setMaxSpeed(defaultSpeed);
                state = PlayerEntity::STATE::DASH_RECHARGE;
            }
        default:
            break;
    }
}

int PlayerEntity::getParryState() const
{
    return parryState;
}

void PlayerEntity::setParryState(int _state)
{
    switch(_state) {
        case PlayerEntity::PARRY_STATE::PARRY_DEFAULT:
            parryState = _state;
            break;
        case PlayerEntity::PARRY_STATE::PARRY_ACTIVE:
            if(parryState != PlayerEntity::PARRY_STATE::PARRY_DEFAULT)
                break;
            parryState = _state;
            parryTimer = maxParryTimer;
            parryHitbox->setPosition(normalize(spawnDirection) * parryHitboxDist);
            break;
        case PlayerEntity::PARRY_STATE::PARRY_RECOVERY:
            if(parryState != PlayerEntity::PARRY_STATE::PARRY_ACTIVE)
                break;
            parryState = _state;
            parryRecoveryTimer = maxParryRecoveryTimer;
            break;
        default:
            break;
    }
}

void PlayerEntity::update(qreal deltaT)
{
    moveBy(direction * speed * deltaT);
    if(state == PlayerEntity::STATE::DASHING) {
        dashTimer -= deltaT;
        if(dashTimer < 0)
            setState(PlayerEntity::STATE::DASH_RECHARGE);
    }
    else if(state == PlayerEntity::STATE::DASH_RECHARGE) {
        dashRechargeTimer -= deltaT;
        if(dashRechargeTimer < 0)
            setState(PlayerEntity::STATE::DEFAULT);
    }

    parryHitbox->setPosition(normalize(spawnDirection) * parryHitboxDist);
    if(parryState == PlayerEntity::PARRY_STATE::PARRY_ACTIVE) {
        parryTimer -= deltaT;
        if(parryTimer < 0)
            setParryState(PlayerEntity::PARRY_STATE::PARRY_RECOVERY);
    }
    else if(parryState == PlayerEntity::PARRY_STATE::PARRY_RECOVERY) {
        parryRecoveryTimer -= deltaT;
        if(parryRecoveryTimer < 0)
            setParryState(PlayerEntity::PARRY_STATE::PARRY_DEFAULT);
    }

    for(int i = 0;i < reloadTimer.size();i++) {
        if(weaponState[i] == PlayerEntity::WEAPON_STATE::READY)
            continue;
        reloadTimer[i] -= deltaT;
        if(reloadTimer[i] < 0)
            weaponState[i] = PlayerEntity::WEAPON_STATE::READY;
    }
}

void PlayerEntity::setSpawnDirection(QPointF _spawnDirection)
{
    spawnDirection = _spawnDirection;
}

QPointF PlayerEntity::getSpawnDirection() const
{
    return spawnDirection;
}

qreal PlayerEntity::getMaxHealth() const
{
    return maxHealth;
}

AbstractHitbox *PlayerEntity::getParryHitbox() const
{
    return parryHitbox;
}

void PlayerEntity::init()
{
    defaultSpeed = 100.0;
    dashSpeed = 500.0;
    maxDashTimer = 0.1;
    maxDashRechargeTimer = 0.5;
    health = 10.0;
    maxHealth = 10.0;
    maxReloadTimer = {0.35, 0.7, 10.0};
    reloadTimer = {0.0, 0.0, 0.0};
    weaponState = {PlayerEntity::WEAPON_STATE::READY, PlayerEntity::WEAPON_STATE::READY, PlayerEntity::WEAPON_STATE::READY};
    weapon = PlayerEntity::WEAPON::PISTOL;

    parryHitboxDist = 10.0;
    parryHitbox = new AbstractHitbox({20, 20}, {0, 0}, this);
    maxParryTimer = 0.1;
    maxParryRecoveryTimer = 1.0;

    setState(PlayerEntity::STATE::DEFAULT);
    setSpawnAction(PlayerEntity::SPAWN_ACTION::NONE);
    setParryState(PlayerEntity::PARRY_STATE::PARRY_DEFAULT);
}


qreal PlayerEntity::healthRatio() const
{
    return health / maxHealth;
}

qreal PlayerEntity::dashRatio() const
{
    return 1.0 - (dashRechargeTimer / maxDashRechargeTimer);
}

qreal PlayerEntity::w1Ratio() const
{
    return 1.0 - reloadTimer[0] / maxReloadTimer[0];
}

qreal PlayerEntity::w2Ratio() const
{
    return 1.0 - reloadTimer[1] / maxReloadTimer[1];
}

qreal PlayerEntity::w3Ratio() const
{
    return 1.0 - reloadTimer[2] / maxReloadTimer[2];
}

qreal PlayerEntity::parryRatio() const
{
    return 1.0 - parryRecoveryTimer / maxParryRecoveryTimer;
}