#include <Interface/Renderer.h>
#include <QGraphicsPixmapItem>

struct {
    QImage* Wall_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* Door_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* MovableEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* PlayerEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
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
    QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(Door_Wrapper *second)
{
    auto* img = Sprites.Wall_Sprite;
    QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(MovableEntity_Wrapper *second)
{
    auto* img = Sprites.Wall_Sprite;
    QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}
