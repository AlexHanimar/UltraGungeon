#pragma once

#include <Entities/Wall.h>
#include <Entities/Door.h>
#include <Entities/MovableEntity.h>
#include <Entities/PlayerEntity.h>
#include <Entities/Projectile.h>

struct AbstractWrapper;

struct Wall_Wrapper;
struct Door_Wrapper;
struct MovableEntity_Wrapper;
struct PlayerEntity_Wrapper;
struct Projectile_Wrapper;


struct Wall_Interaction;
struct Door_Interaction;
struct MovableEntity_Interaction;
struct PlayerEntity_Interaction;
struct Projectile_Interaction;



// abstract
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct AbstractInteraction {
    virtual void apply(Wall_Wrapper *) = 0;
    virtual void apply(Door_Wrapper *) = 0;
    virtual void apply(MovableEntity_Wrapper *) = 0;
    virtual void apply(PlayerEntity_Wrapper *) = 0;
    virtual void apply(Projectile_Wrapper *) = 0;
};

struct AbstractWrapper {
    bool markedForDeletion = false;
    virtual AbstractInteraction *generateInteraction() = 0;
    virtual void accept(AbstractInteraction *interaction) = 0;
};
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// wrappers
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct Wall_Wrapper : public AbstractWrapper {
    Wall* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};
struct Door_Wrapper : public AbstractWrapper {
    Door* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};
struct MovableEntity_Wrapper : public AbstractWrapper {
    MovableEntity* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};
struct PlayerEntity_Wrapper : public AbstractWrapper {
    PlayerEntity* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};
struct Projectile_Wrapper : public AbstractWrapper {
    Projectile* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
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
};
struct Door_Interaction : public AbstractInteraction {
    Door_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};
struct MovableEntity_Interaction : public AbstractInteraction {
    MovableEntity_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};
struct PlayerEntity_Interaction : public AbstractInteraction {
    PlayerEntity_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};
struct Projectile_Interaction : public AbstractInteraction {
    Projectile_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
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
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^