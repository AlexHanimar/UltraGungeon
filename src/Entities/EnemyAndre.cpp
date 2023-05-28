#include <Entities/EnemyAndre.h>
#include <Helpers/Helpers.h>
#include <QDebug>

void EnemyAndre::setHitboxActive(bool _nactive)
{
    hitboxActive = _nactive;
}

bool EnemyAndre::hitboxIsActive() const
{
    return hitboxActive;
}

int EnemyAndre::getSpawnAction() const
{
    return spawnAction;
}

void EnemyAndre::setSpawnAction(int _spawn_action)
{
    switch(_spawn_action) {
        case EnemyAndre::SPAWN_ACTION::NONE:
            spawnAction = _spawn_action;
            break;
        case EnemyAndre::SPAWN_ACTION::BALL:
            spawnAction = _spawn_action;
            break;
        default:
            break;
    }
}

QPointF EnemyAndre::getSpawnDirection() const
{
    return spawnDirection;
}

void EnemyAndre::setSpawnDirection(QPointF _spawn_direction)
{
    spawnDirection = _spawn_direction;
}

qreal EnemyAndre::getDamage() const
{
    return bodyDamage;
}

void EnemyAndre::setState(int _state)
{
    switch(_state) {
        case EnemyAndre::STATE::DEFAULT:
            setMaxSpeed(defaultSpeed);
            setSpeed(defaultSpeed);
            setSpawnAction(EnemyAndre::SPAWN_ACTION::NONE);
            state = _state;
            break;
        case EnemyAndre::STATE::DASHING:
            if(state == EnemyAndre::STATE::DEFAULT) {
                setHitboxActive(true);
                setMaxSpeed(dashSpeed);
                setSpeed(dashSpeed);
                dashTimer = maxDashTimer;
                state = _state;
            }
            break;
        case EnemyAndre::STATE::SHOOTING:
            if(state == EnemyAndre::STATE::DEFAULT) {
                setMaxSpeed(0);
                chargeUpTimer = maxChargeUpTimer;
                state = _state;
            }
            break;
        case EnemyAndre::STATE::RECOVERY:
            setHitboxActive(false);
            setMaxSpeed(recoverySpeed);
            setDirection(destination - getAbsolutePosition());
            setSpeed(recoverySpeed);
            if(state == EnemyAndre::STATE::DASHING) {
                recoveryTimer = maxRecoveryTimer;
                state = _state;
            }
            else if(state == EnemyAndre::STATE::SHOOTING) {
                setSpawnAction(EnemyAndre::SPAWN_ACTION::BALL);
                setSpawnDirection(destination - getAbsolutePosition());
                recoveryTimer = maxRecoveryTimer;
                state = _state;
            }
            break;
        default:
            break;
    }
}

void EnemyAndre::update(qreal deltaT)
{
    switch(state) {
        case EnemyAndre::STATE::DEFAULT:
            if(module(destination - getAbsolutePosition()) < dashRadius) {
                setDirection(destination - getAbsolutePosition());
                setState(EnemyAndre::STATE::DASHING);
            }
            else {
                setDirection(destination - getAbsolutePosition());
                setState(EnemyAndre::STATE::SHOOTING);
            }
            break;
        case EnemyAndre::STATE::DASHING:
            dashTimer -= deltaT;
            if(dashTimer < 0)
                setState(EnemyAndre::STATE::RECOVERY);
            break;
        case EnemyAndre::STATE::SHOOTING:
            chargeUpTimer -= deltaT;
            if(chargeUpTimer < 0)
                setState(EnemyAndre::STATE::RECOVERY);
            break;
        case EnemyAndre::STATE::RECOVERY:
            setDirection(destination - getAbsolutePosition());
            recoveryTimer -= deltaT;
            if(recoveryTimer < 0)
                setState(EnemyAndre::STATE::DEFAULT);
            break;
        default:
            break;
    }
    moveBy(direction * speed * deltaT);
}

void EnemyAndre::init()
{
    health = 30.0;
    maxHealth = 30.0;
    bodyDamage = 3.0;

    defaultSpeed = 50.0;
    recoverySpeed = 50.0;
    dashSpeed = 500.0;

    maxDashTimer = 0.5;
    maxRecoveryTimer = 2.0;
    maxChargeUpTimer = 0.5;
    dashRadius = 200.0;

    setState(EnemyAndre::STATE::DEFAULT);
}

EnemyAndre::EnemyAndre(QPointF pos) : AbstractEnemy(0, {20, 20}, pos)
{
    EnemyAndre::init();
}