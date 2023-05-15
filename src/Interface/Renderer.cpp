#include <Interface/Renderer.h>
#include <QGraphicsPixmapItem>

struct {
    QImage* Wall_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* Door_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* MovableEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
} Sprites;

AbstractInteraction *Renderer_Wrapper::generateInteraction()
{
    auto* inter = new Renderer_Interaction;
    inter->first = this;
    return inter;
}

void Renderer_Wrapper::accept(AbstractInteraction *interaction) {}

void Renderer_Interaction::apply(Wall_Wrapper *second)
{
    auto* img = Sprites.Wall_Sprite;
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    QPoint dPos(int(-img->width() * 0.5), int(-img->height() * 0.5));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(Door_Wrapper *second)
{
    auto* img = Sprites.Door_Sprite;
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    QPoint dPos(int(-img->width() * 0.5), int(-img->height() * 0.5));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(MovableEntity_Wrapper *second)
{
    auto* img = Sprites.MovableEntity_Sprite;
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    QPoint dPos(int(-img->width() * 0.5), int(-img->height() * 0.5));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}