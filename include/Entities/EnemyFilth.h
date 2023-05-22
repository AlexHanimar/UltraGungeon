#pragma once

#include <Entities/AbstractEnemy.h>

class EnemyFilth : public AbstractEnemy {
protected:
    qreal damage;
    qreal dashSpeed;
    qreal recoverySpeed;

    qreal dashTimer;
    qreal maxDashTimer;
    qreal recoveryTimer;
    qreal maxRecoveryTimer;

    qreal dashRadius;
    bool hitboxActive;
public:
    using AbstractEnemy::AbstractEnemy;

    enum STATE {
        DEFAULT = 0,
        DASHING = 1,
        RECOVERY = 2
    };

    void setState(int _state) override;
    void update(qreal deltaT) override;
    void init() override;
    [[nodiscard("EnemyFilth::getDamage() unused")]] qreal getDamage() const;

    [[nodiscard("EnemyFilth::hitboxIsActive() unused")]] bool hitboxIsActive() const;
    void setHitboxActive(bool _nactive);
};