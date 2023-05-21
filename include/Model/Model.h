#pragma once

#include <Model/EntityWrapper.h>
#include <vector>

// Time interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct Time_Wrapper;
struct Time_Interaction;

struct Time_Wrapper : public AbstractWrapper {
    qreal* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};
struct Time_Interaction : public AbstractInteraction {
    Time_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};
AbstractWrapper* wrap(qreal* timeItem);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Input interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct Input_Wrapper;
struct Input_Interaction;

struct Input_Wrapper : public AbstractWrapper {
    int* item;
    QPointF* mouseDir;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};
struct Input_Interaction : public AbstractInteraction {
    Input_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};
AbstractWrapper* wrap(int* inputItem, QPointF* mouseItem);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Spawn interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct Spawn_Wrapper;
struct Spawn_Interaction;

struct Spawn_Wrapper : public AbstractWrapper {
    std::vector<AbstractWrapper*>* item;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};

struct Spawn_Interaction : public AbstractInteraction {
    Spawn_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Despawn interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
struct Despawn_Wrapper;
struct Despawn_Interaction;

struct Despawn_Wrapper : public AbstractWrapper {
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
};

struct Despawn_Interaction : public AbstractInteraction {
    Despawn_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

enum INPUT {
    KEY_W =     0b000000000001,
    KEY_A =     0b000000000010,
    KEY_S =     0b000000000100,
    KEY_D =     0b000000001000,
    KEY_DASH =  0b000000010000,
    MOUSE_1 =   0b100000000000,
    MOUSE_2 =   0b010000000000,
    KEY_1 =     0b001000000000,
    KEY_2 =     0b000100000000,
    KEY_3 =     0b000010000000
};

class Model {
protected:
    int inputMask;
    QPointF mouseDirection;
    std::vector<AbstractWrapper*> entities;
    AbstractWrapper* playerEntity;
    AbstractWrapper* spawnWrapper;
    AbstractWrapper* despawnWrapper;
public:
    Model();
    void update(qreal deltaT);
    [[nodiscard("Model::getEntities() unused")]] std::vector<AbstractWrapper*> getEntities() const;
    [[nodiscard("Model::getPlayerEntity() unused")]] AbstractWrapper* getPlayerEntity() const;

    void setPlayerEntity(PlayerEntity* player);

    void addEntity(AbstractWrapper* entity);

    void setInputMask(int _inputMask);
    void setMouseDirection(QPointF _mouseDirection);
};