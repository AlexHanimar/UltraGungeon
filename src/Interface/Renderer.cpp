#include <Interface/Renderer.h>
#include <QGraphicsPixmapItem>

AbstractInteraction *Renderer_Wrapper::generateInteraction()
{
    auto* inter = new Renderer_Interaction;
    inter->first = this;
    return inter;
}

void Renderer_Wrapper::accept(AbstractInteraction *interaction) {}

void Renderer_Interaction::apply(Wall_Wrapper *second)
{
    QImage img("../../sprites/defaultSprite.png");
    /*auto size = second->item->getCollider()->getSize();
    img = img.scaled(QSize(size.width(), size.height()));*/
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img));
    item->setPos((second->item->getAbsolutePosition() - QPoint(img.width() * 0.5, img.height() * 0.5)) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(Door_Wrapper *second)
{
    QImage img("../../sprites/defaultSprite.png");
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img));
    item->setPos((second->item->getAbsolutePosition() - QPoint(img.width() * 0.5, img.height() * 0.5)) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(MovableEntity_Wrapper *second)
{
    QImage img("../../sprites/defaultSprite.png");
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img));
    item->setPos((second->item->getAbsolutePosition() - QPoint(img.width() * 0.5, img.height() * 0.5)) * first->scale);
    item->setScale(first->scale);
}