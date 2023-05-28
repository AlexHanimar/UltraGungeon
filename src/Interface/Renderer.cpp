#include <Interface/Renderer.h>
#include <QGraphicsPixmapItem>

struct {
    QImage* Wall_Sprite = new QImage("../../sprites/Wall_sprite.png");
    QImage* Door_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* MovableEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* PlayerEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* Projectile_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* EnemyFilth_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* EnemyAndre_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* AndreBallProjectile_Sprite = new QImage("../../sprites/AndreBallProjectile_sprite.png");
    QImage* ParryProjectile_Sprite = new QImage("../../sprites/ParryProjectile_sprite.png");
} Sprites;

Renderer_Interaction::~Renderer_Interaction() = default;
Renderer_Wrapper::~Renderer_Wrapper()
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
    auto size = second->item->getCollider()->getSize().toSize();
    auto* img = new QImage(Sprites.Wall_Sprite->scaled(size));
    QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);

    delete img;
}

void Renderer_Interaction::apply(Door_Wrapper *second)
{
    auto* img = Sprites.Door_Sprite;
    QImage img2 = img->scaled(second->item->getCollider()->getSize().width(), second->item->getCollider()->getSize().height());
    QPoint dPos = QPoint(-img2.width() * 0.5, -img2.height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img2));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(MovableEntity_Wrapper *second)
{
    auto* img = Sprites.MovableEntity_Sprite;
    QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(*img));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(PlayerEntity_Wrapper *second)
{
    first->view->centerOn(second->item->getAbsolutePosition() * first->scale);
    {
        auto *img = Sprites.PlayerEntity_Sprite;
        QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
        auto *item = first->scene->addPixmap(QPixmap::fromImage(*img));
        item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
        item->setScale(first->scale);
    }
    {
        auto *img = Sprites.PlayerEntity_Sprite;
        QPoint dPos = QPoint(-img->width() * 0.5, -img->height() * 0.5);
        int width = 10 * second->item->getHealth() / second->item->getMaxHealth();
        auto *item = first->scene->addRect(0, 0, width, 3, QPen(Qt::green), QBrush(Qt::green));
        item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
        item->setScale(first->scale);
    }
    {
        auto size = second->item->getParryHitbox()->getSize();
        int width = size.width(), height = size.height();
        auto col = Qt::red;
        if(second->item->getParryState() == PlayerEntity::PARRY_STATE::PARRY_ACTIVE)
            col = Qt::green;
        auto* item = first->scene->addRect(-width * 0.5, -height * 0.5, width, height, QPen(col));
        item->setPos((second->item->getParryHitbox()->getAbsolutePosition()) * first->scale);
        item->setScale(first->scale);
    }

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

void Renderer_Interaction::apply(EnemyAndre_Wrapper *second)
{
    auto* img = Sprites.EnemyAndre_Sprite;
    QSizeF size = second->item->getCollider()->getSize();
    QImage img2 = img->scaled(size.width(), size.height());
    QPoint dPos = QPoint(-img2.width() * 0.5, -img2.height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img2));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(Trigger_Wrapper *second)
{
    auto col = Qt::green;
    if(second->item->getState() == Trigger::STATE::TRIGGERED)
        col = Qt::blue;
    if(second->item->getState() == Trigger::STATE::DISABLED)
        col = Qt::red;
    QPoint dPos = QPoint(-second->item->getSize().width() * 0.5, -second->item->getSize().height() * 0.5);
    QRect rect(dPos + QPoint(second->item->getAbsolutePosition().x(), second->item->getAbsolutePosition().y()),
               QSize(second->item->getSize().width(), second->item->getSize().height()));
    auto* item = first->scene->addRect(rect, QPen(col));
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(Hitscan_Wrapper *second)
{
    if(second->item->getState() == Hitscan::STATE::CHARGED)
        return;
    auto col = Qt::yellow;
    auto* item = first->scene->addLine(QLineF(second->item->getStartPoint(), second->item->getEndpoint()), QPen(col, 3));
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(PistolHitscan_Wrapper *second)
{
    if(second->item->getState() == Hitscan::STATE::CHARGED)
        return;
    auto col = Qt::yellow;
    auto* item = first->scene->addLine(QLineF(second->item->getStartPoint(), second->item->getEndpoint()), QPen(col, 2));
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(BlueRailcannonHitscan_Wrapper *second)
{
    if(second->item->getState() == Hitscan::STATE::CHARGED)
        return;
    auto col = Qt::cyan;
    auto* item = first->scene->addLine(QLineF(second->item->getStartPoint(), second->item->getEndpoint()), QPen(col, 4));
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(AndreBallProjectile_Wrapper *second)
{
    auto* img = Sprites.AndreBallProjectile_Sprite;
    QSizeF size = second->item->getCollider()->getSize();
    QImage img2 = img->scaled(size.width(), size.height());
    QPoint dPos = QPoint(-img2.width() * 0.5, -img2.height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img2));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(ParryProjectile_Wrapper *second)
{
    auto* img = Sprites.ParryProjectile_Sprite;
    QSizeF size = second->item->getCollider()->getSize();
    QImage img2 = img->scaled(size.width(), size.height());
    QPoint dPos = QPoint(-img2.width() * 0.5, -img2.height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img2));
    item->setPos((second->item->getAbsolutePosition() + dPos) * first->scale);
    item->setScale(first->scale);
}