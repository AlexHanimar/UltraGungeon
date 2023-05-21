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
};

struct Renderer_Interaction : public AbstractInteraction {
    Renderer_Wrapper* first;
    void apply(Wall_Wrapper* second) override;
    void apply(Door_Wrapper* second) override;
    void apply(MovableEntity_Wrapper* second) override;
    void apply(PlayerEntity_Wrapper* second) override;
    void apply(Projectile_Wrapper* second) override;
};