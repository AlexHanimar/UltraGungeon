#include <Interface/Renderer.h>
#include <QGraphicsPixmapItem>

struct {
    QImage* Wall_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* Door_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* MovableEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* PlayerEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* Projectile_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* EnemyFilth_Sprite = new QImage("../../sprites/defaultSprite.png");
} Sprites;

Renderer_Interaction::~Renderer_Interaction() noexcept {}
Renderer_Wrapper::~Renderer_Wrapper() noexcept
{
    scene = nullptr;
    view = nullptr;
    delete scene;
    delete view;
}

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

void Renderer_Interaction::apply(PlayerEntity_Wrapper *second)
{
    first->view->centerOn(second->item->getAbsolutePosition() * first->scale);
    auto* img = Sprites.PlayerEntity_Sprite;
    QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);

    int width = 10 * second->item->getHealth() / second->item->getMaxHealth();
    auto* item2 = first->scene->addRect(0, 0, width, 3, QPen(Qt::green), QBrush(Qt::green));
    item2->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item2->setScale(first->scale);
}

void Renderer_Interaction::apply(Projectile_Wrapper *second)
{
    auto* img = Sprites.Projectile_Sprite;
    QSizeF size = second->item->getCollider()->getSize();
    QImage img2 = img->scaled(size.width(), size.height());
    QPoint dPos = QPoint(-img2.width() * 0.5, -img2.height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img2));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(EnemyFilth_Wrapper *second)
{
    auto* img = Sprites.EnemyFilth_Sprite;
    QSizeF size = second->item->getCollider()->getSize();
    QImage img2 = img->scaled(size.width(), size.height());
    QPoint dPos = QPoint(-img2.width() * 0.5, -img2.height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img2));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}