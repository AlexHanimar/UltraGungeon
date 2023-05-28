#include <Entities/EnemyFilth.h>
#include <Helpers/Helpers.h>
#include <QDebug>

qreal EnemyFilth::getDamage() const
{
    return damage;
}

void EnemyFilth::setState(int _state)
{
    switch(_state) {
        case EnemyFilth::STATE::DEFAULT:
            setMaxSpeed(defaultSpeed);
            setSpeed(defaultSpeed);
            state = _state;
            break;
        case EnemyFilth::STATE::DASHING:
            if(state == EnemyFilth::STATE::DEFAULT) {
                setMaxSpeed(dashSpeed);
                setSpeed(dashSpeed);
                setHitboxActive(true);
                dashTimer = maxDashTimer;
                state = _state;
            }
            break;
        case EnemyFilth::STATE::RECOVERY:
            if(state == EnemyFilth::STATE::DASHING) {
                setMaxSpeed(recoverySpeed);
                setSpeed(recoverySpeed);
                setHitboxActive(false);
                recoveryTimer = maxRecoveryTimer;
                state = _state;
            }
            break;
        default:
            break;
    }
}

void EnemyFilth::update(qreal deltaT)
{
    switch(state) {
        case EnemyFilth::STATE::DEFAULT:
            if(module(destination - getAbsolutePosition()) < dashRadius) {
                setState(EnemyFilth::STATE::DASHING);
                setDirection(destination - getAbsolutePosition());
            }
            else {
                QPointF dir = normalize(destination - getAbsolutePosition());
                setVelocity(getVelocity() + dir * maxSpeed);
            }
            break;
        case EnemyFilth::STATE::DASHING:
            dashTimer -= deltaT;
            if(dashTimer < 0)
                setState(EnemyFilth::STATE::RECOVERY);
            break;
        case EnemyFilth::STATE::RECOVERY:
            setDirection(destination - getAbsolutePosition());
            recoveryTimer -= deltaT;
            if(recoveryTimer < 0)
                setState(EnemyFilth::STATE::DEFAULT);
            break;
        default:
            break;
    }
    moveBy(direction * speed * deltaT);
}

bool EnemyFilth::hitboxIsActive() const
{
    return hitboxActive;
}

void EnemyFilth::setHitboxActive(bool _nactive)
{
    hitboxActive = _nactive;
}

void EnemyFilth::init()
{
    damage = 1.0;
    defaultSpeed = 100.0;
    dashSpeed = 500.0;
    recoverySpeed = 20.0;
    maxDashTimer = 0.1;
    maxRecoveryTimer = 0.5;
    health = 1.0;
    maxHealth = 1.0;
    dashRadius = 100.0;
    setState(EnemyFilth::DEFAULT);
}

EnemyFilth::EnemyFilth(QPointF pos)
    : AbstractEnemy(0, {10, 10}, pos)
{
    EnemyFilth::init();
}