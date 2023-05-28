#pragma once

#include <Entities/Wall.h>
#include <Entities/Door.h>
#include <Entities/MovableEntity.h>
#include <Entities/PlayerEntity.h>
#include <Entities/Projectile.h>
#include <Entities/EnemyFilth.h>
#include <Entities/EnemyAndre.h>
#include <Entities/Trigger.h>
#include <Entities/Hitscan.h>
#include <Entities/PistolHitscan.h>
#include <Entities/BlueRailgunHitscan.h>
#include <Entities/AndreBallProjectile.h>
#include <Entities/ParryProjectile.h>
#include <Entities/ShotgunPelletProjectile.h>
#include <Entities/Explosion.h>
#include <Entities/Coin.h>

struct AbstractWrapper;

struct Wall_Wrapper;
struct Door_Wrapper;
struct MovableEntity_Wrapper;
struct PlayerEntity_Wrapper;
struct Projectile_Wrapper;
struct EnemyFilth_Wrapper;
struct EnemyAndre_Wrapper;
struct Trigger_Wrapper;
struct Hitscan_Wrapper;
struct PistolHitscan_Wrapper;
struct BlueRailgunHitscan_Wrapper;
struct AndreBallProjectile_Wrapper;
struct ParryProjectile_Wrapper;
struct ShotgunPelletProjectile_Wrapper;
struct Explosion_Wrapper;
struct Coin_Wrapper;



struct Wall_Interaction;
struct Door_Interaction;
struct MovableEntity_Interaction;
struct PlayerEntity_Interaction;
struct Projectile_Interaction;
struct EnemyFilth_Interaction;
struct EnemyAndre_Interaction;
struct Trigger_Interaction;
struct Hitscan_interaction;
struct PistolHitscan_Interaction;
struct BlueRailgunHitscan_Interaction;
struct AndreBallProjectile_Interaction;
struct ParryProjectile_Interaction;
struct ShotgunPelletProjectile_Interaction;
struct Explosion_Interaction;
struct Coin_Interaction;


// abstract
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct AbstractInteraction {
    virtual void apply(Wall_Wrapper *) = 0;
    virtual void apply(Door_Wrapper *) = 0;
    virtual void apply(MovableEntity_Wrapper *) = 0;
    virtual void apply(PlayerEntity_Wrapper *) = 0;
    virtual void apply(Projectile_Wrapper *) = 0;
    virtual void apply(EnemyFilth_Wrapper *) = 0;
    virtual void apply(EnemyAndre_Wrapper *) = 0;
    virtual void apply(Trigger_Wrapper *)  = 0;
    virtual void apply(Hitscan_Wrapper *) = 0;
    virtual void apply(PistolHitscan_Wrapper *) = 0;
    virtual void apply(BlueRailgunHitscan_Wrapper *) = 0;
    virtual void apply(AndreBallProjectile_Wrapper *) = 0;
    virtual void apply(ParryProjectile_Wrapper *) = 0;
    virtual void apply(ShotgunPelletProjectile_Wrapper *) = 0;
    virtual void apply(Explosion_Wrapper *) = 0;
    virtual void apply(Coin_Wrapper *) = 0;

    virtual ~AbstractInteraction();
};

struct AbstractWrapper {
    bool markedForDeletion = false;
    virtual AbstractInteraction *generateInteraction() = 0;
    virtual void accept(AbstractInteraction *interaction) = 0;

    virtual ~AbstractWrapper();
};
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// wrappers
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct Wall_Wrapper : public AbstractWrapper {
    Wall* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~Wall_Wrapper() override = default;
};
struct Door_Wrapper : public AbstractWrapper {
    Door* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~Door_Wrapper() override = default;
};
struct MovableEntity_Wrapper : public AbstractWrapper {
    MovableEntity* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~MovableEntity_Wrapper() override = default;
};
struct PlayerEntity_Wrapper : public AbstractWrapper {
    PlayerEntity* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~PlayerEntity_Wrapper() override = default;
};
struct Projectile_Wrapper : public AbstractWrapper {
    Projectile* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~Projectile_Wrapper() override = default;
};
struct EnemyFilth_Wrapper : public AbstractWrapper {
    EnemyFilth* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~EnemyFilth_Wrapper() override = default;
};
struct EnemyAndre_Wrapper : public AbstractWrapper {
    EnemyAndre* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~EnemyAndre_Wrapper() override = default;
};
struct Trigger_Wrapper : public AbstractWrapper {
    Trigger* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~Trigger_Wrapper() override = default;
};
struct Hitscan_Wrapper : public AbstractWrapper {
    Hitscan* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~Hitscan_Wrapper() override = default;
};
struct PistolHitscan_Wrapper : public AbstractWrapper {
    PistolHitscan* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~PistolHitscan_Wrapper() override = default;
};
struct BlueRailgunHitscan_Wrapper : public AbstractWrapper {
    BlueRailgunHitscan* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~BlueRailgunHitscan_Wrapper() override = default;
};
struct AndreBallProjectile_Wrapper : public AbstractWrapper {
    AndreBallProjectile* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~AndreBallProjectile_Wrapper() override = default;
};
struct ParryProjectile_Wrapper : public AbstractWrapper {
    ParryProjectile* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~ParryProjectile_Wrapper() override = default;
};
struct ShotgunPelletProjectile_Wrapper : public AbstractWrapper {
    ShotgunPelletProjectile* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~ShotgunPelletProjectile_Wrapper() override = default;
};
struct Explosion_Wrapper : public AbstractWrapper {
    Explosion* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~Explosion_Wrapper() override = default;
};
struct Coin_Wrapper : public AbstractWrapper {
    Coin* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    ~Coin_Wrapper() override = default;
};
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// interactions
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct Wall_Interaction : public AbstractInteraction {
    Wall_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~Wall_Interaction() override;
};
struct Door_Interaction : public AbstractInteraction {
    Door_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~Door_Interaction() override;
};
struct MovableEntity_Interaction : public AbstractInteraction {
    MovableEntity_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~MovableEntity_Interaction() override;
};
struct PlayerEntity_Interaction : public AbstractInteraction {
    PlayerEntity_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~PlayerEntity_Interaction() override;
};
struct Projectile_Interaction : public AbstractInteraction {
    Projectile_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~Projectile_Interaction() override;
};
struct EnemyFilth_Interaction : public AbstractInteraction {
    EnemyFilth_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~EnemyFilth_Interaction() override;
};
struct EnemyAndre_Interaction : public AbstractInteraction {
    EnemyAndre_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~EnemyAndre_Interaction() override;
};
struct Trigger_Interaction : public AbstractInteraction {
    Trigger_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~Trigger_Interaction() override;
};
struct Hitscan_Interaction : public AbstractInteraction {
    Hitscan_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~Hitscan_Interaction() override;
};
struct PistolHitscan_Interaction : public AbstractInteraction {
    PistolHitscan_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~PistolHitscan_Interaction() override;
};
struct BlueRailgunHitscan_Interaction : public AbstractInteraction {
    BlueRailgunHitscan_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~BlueRailgunHitscan_Interaction() override;
};
struct AndreBallProjectile_Interaction : public AbstractInteraction {
    AndreBallProjectile_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~AndreBallProjectile_Interaction() override;
};
struct ParryProjectile_Interaction : public AbstractInteraction {
    ParryProjectile_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~ParryProjectile_Interaction() override;
};
struct ShotgunPelletProjectile_Interaction : public AbstractInteraction {
    ShotgunPelletProjectile_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~ShotgunPelletProjectile_Interaction() override;
};
struct Explosion_Interaction : public AbstractInteraction {
    Explosion_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~Explosion_Interaction() override;
};
struct Coin_Interaction : public AbstractInteraction {
    Coin_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    void apply(EnemyAndre_Wrapper* second) override;
    void apply(Trigger_Wrapper* second) override;
    void apply(Hitscan_Wrapper* second) override;
    void apply(PistolHitscan_Wrapper* second) override;
    void apply(BlueRailgunHitscan_Wrapper* second) override;
    void apply(AndreBallProjectile_Wrapper* second) override;
    void apply(ParryProjectile_Wrapper* second) override;
    void apply(ShotgunPelletProjectile_Wrapper* second) override;
    void apply(Explosion_Wrapper* second) override;
    void apply(Coin_Wrapper* second) override;
    ~Coin_Interaction() override;
};
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



// general interaction function
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void interact(AbstractWrapper* a, AbstractWrapper* b);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// generating Wrappers
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractWrapper* wrap(Wall* item);
AbstractWrapper* wrap(Door* item);
AbstractWrapper* wrap(MovableEntity* item);
AbstractWrapper* wrap(PlayerEntity* item);
AbstractWrapper* wrap(Projectile* item);
AbstractWrapper* wrap(EnemyFilth* item);
AbstractWrapper* wrap(EnemyAndre* item);
AbstractWrapper* wrap(Trigger* item);
AbstractWrapper* wrap(Hitscan* item);
AbstractWrapper* wrap(PistolHitscan* item);
AbstractWrapper* wrap(BlueRailgunHitscan* item);
AbstractWrapper* wrap(AndreBallProjectile* item);
AbstractWrapper* wrap(ParryProjectile* item);
AbstractWrapper* wrap(ShotgunPelletProjectile* item);
AbstractWrapper* wrap(Explosion* item);
AbstractWrapper* wrap(Coin* item);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^