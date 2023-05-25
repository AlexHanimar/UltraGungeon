#include <Interface/Renderer.h>
#include <QGraphicsPixmapItem>

struct {
    QImage* Wall_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* Door_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* MovableEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* PlayerEntity_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* Projectile_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* EnemyFilth_Sprite = new QImage("../../sprites/defaultSprite.png");
    QImage* EnemyAndre_Sprite = new QImage("../../sprites/defaultSprite.png");
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
    QImage img2 = img->scaled(second->item->getCollider()->getSize().width(), second->item->getCollider()->getSize().height());
    QPoint dPos = QPoint(-img2.width() * 0.5, -img2.height() * 0.5);
    auto* item = first->scene->addPixmap(QPixmap::fromImage(img2));
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
    if(second->item->isTriggered())
        col = Qt::red;
    QPoint dPos = QPoint(-second->item->getSize().width() * 0.5, -second->item->getSize().height() * 0.5);
    QRect rect(dPos + QPoint(second->item->getAbsolutePosition().x(), second->item->getAbsolutePosition().y()),
               QSize(second->item->getSize().width(), second->item->getSize().height()));
    auto* item = first->scene->addRect(rect, QPen(col));
    item->setScale(first->scale);
}

void Renderer_Interaction::apply(Hitscan_Wrapper *second)
{
    auto col = Qt::yellow;
    auto* item = first->scene->addLine(QLineF(second->item->getStartPoint(), second->item->getEndpoint()), QPen(col, 3));
    item->setScale(first->scale);
}