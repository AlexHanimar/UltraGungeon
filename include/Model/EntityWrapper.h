#pragma once

#include <Entities/Wall.h>
#include <Entities/Door.h>
#include <Entities/MovableEntity.h>
#include <Entities/PlayerEntity.h>
#include <Entities/Projectile.h>
#include <Entities/EnemyFilth.h>

struct AbstractWrapper;

struct Wall_Wrapper;
struct Door_Wrapper;
struct MovableEntity_Wrapper;
struct PlayerEntity_Wrapper;
struct Projectile_Wrapper;
struct EnemyFilth_Wrapper;


struct Wall_Interaction;
struct Door_Interaction;
struct MovableEntity_Interaction;
struct PlayerEntity_Interaction;
struct Projectile_Interaction;
struct EnemyFilth_Interaction;



// abstract
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct AbstractInteraction {
    virtual void apply(Wall_Wrapper *) = 0;
    virtual void apply(Door_Wrapper *) = 0;
    virtual void apply(MovableEntity_Wrapper *) = 0;
    virtual void apply(PlayerEntity_Wrapper *) = 0;
    virtual void apply(Projectile_Wrapper *) = 0;
    virtual void apply(EnemyFilth_Wrapper *) = 0;

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
    virtual ~Wall_Wrapper() override = default;
};
struct Door_Wrapper : public AbstractWrapper {
    Door* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    virtual ~Door_Wrapper() override = default;
};
struct MovableEntity_Wrapper : public AbstractWrapper {
    MovableEntity* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    virtual ~MovableEntity_Wrapper() override = default;
};
struct PlayerEntity_Wrapper : public AbstractWrapper {
    PlayerEntity* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    virtual ~PlayerEntity_Wrapper() override = default;
};
struct Projectile_Wrapper : public AbstractWrapper {
    Projectile* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    virtual ~Projectile_Wrapper() override = default;
};
struct EnemyFilth_Wrapper : public AbstractWrapper {
    EnemyFilth* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    virtual ~EnemyFilth_Wrapper() override = default;
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
    virtual ~Wall_Interaction() override;
};
struct Door_Interaction : public AbstractInteraction {
    Door_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    virtual ~Door_Interaction() override;
};
struct MovableEntity_Interaction : public AbstractInteraction {
    MovableEntity_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    virtual ~MovableEntity_Interaction() override;
};
struct PlayerEntity_Interaction : public AbstractInteraction {
    PlayerEntity_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    virtual ~PlayerEntity_Interaction() override;
};
struct Projectile_Interaction : public AbstractInteraction {
    Projectile_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    virtual ~Projectile_Interaction() override;
};
struct EnemyFilth_Interaction : public AbstractInteraction {
    EnemyFilth_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
    void apply(EnemyFilth_Wrapper* second) override;
    virtual ~EnemyFilth_Interaction() override;
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
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^