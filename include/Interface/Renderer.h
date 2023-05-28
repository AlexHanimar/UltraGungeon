#pragma once

#include <QGraphicsScene>
#include <QgraphicsView>
#include <Model/EntityWrapper.h>

struct Renderer_Interaction;

struct Renderer_Wrapper : public AbstractWrapper {
    QGraphicsScene* scene;
    QGraphicsView* view;
    qreal scale;
    AbstractInteraction* generateInteraction() override;
    void accept(AbstractInteraction* interaction) override;
    virtual ~Renderer_Wrapper() override;
};

struct Renderer_Interaction : public AbstractInteraction {
    Renderer_Wrapper* first;
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
    virtual ~Renderer_Interaction() override;
};