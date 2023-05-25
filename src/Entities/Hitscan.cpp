#include <Entities/Hitscan.h>
#include <QLineF>
#include <QPolygonF>
#include <QDebug>

int Hitscan::getState() const
{
    return state;
}

void Hitscan::setState(int _state)
{
    switch(_state) {
        case Hitscan::STATE::DEFAULT:
            state = _state;
            break;
        case Hitscan::STATE::DESTROYED:
            state = _state;
            break;
        default:
            break;
    }
}

qreal Hitscan::getDamage() const
{
    return damage;
}

QPointF Hitscan::getStartPoint() const
{
    return position;
}

void Hitscan::update(qreal deltaT)
{
    lifeTime -= deltaT;
    if(lifeTime < 0)
        setState(Hitscan::STATE::DESTROYED);
}

void Hitscan::init(QPointF _pos, QPointF _dir, int _pierce, qreal _damage, qreal _maxLifeTime)
{
    position = _pos;
    direction = normalize(_dir);
    pierce = _pierce;
    damage = _damage;
    maxLifeTime = _maxLifeTime;
    lifeTime = maxLifeTime;
    setState(Hitscan::STATE::DEFAULT);
}

void Hitscan::addPierce(AbstractHitbox *hitbox)
{
    if(std::find(pierced.begin(), pierced.end(), hitbox) != pierced.end())
        return;
    QLineF hitLine(position, position + direction * 100000.0);
    QPointF a = hitbox->getAbsolutePosition() + QPointF(-hitbox->getSize().width(), -hitbox->getSize().height()) * 0.5;
    QPointF b = hitbox->getAbsolutePosition() + QPointF(-hitbox->getSize().width(), hitbox->getSize().height()) * 0.5;
    QPointF c = hitbox->getAbsolutePosition() + QPointF(hitbox->getSize().width(), hitbox->getSize().height()) * 0.5;
    QPointF d = hitbox->getAbsolutePosition() + QPointF(hitbox->getSize().width(), -hitbox->getSize().height()) * 0.5;
    std::vector<QLineF> lines = {QLineF(a, b), QLineF(b, c), QLineF(c, d), QLineF(d, a)};
    for(const auto& line : lines) {
        QPointF* interPoint = new QPointF();
        auto inter = hitLine.intersects(line, interPoint);
        if(inter == QLineF::IntersectionType::BoundedIntersection) {
            pierced.push_back(hitbox);
            delete interPoint;
            return;
        }
        delete interPoint;
    }
    return;
}

QPointF Hitscan::getEndpoint() const
{
    if(pierced.size() == 0)
        return position + direction * 100000.0;
    std::vector<QPointF> interPoints;
    QLineF hitLine(position, position + direction * 100000.0);
    for(auto* hitbox : pierced) {
        QPointF a = hitbox->getAbsolutePosition() + QPointF(-hitbox->getSize().width(), -hitbox->getSize().height()) * 0.5;
        QPointF b = hitbox->getAbsolutePosition() + QPointF(-hitbox->getSize().width(), hitbox->getSize().height()) * 0.5;
        QPointF c = hitbox->getAbsolutePosition() + QPointF(hitbox->getSize().width(), hitbox->getSize().height()) * 0.5;
        QPointF d = hitbox->getAbsolutePosition() + QPointF(hitbox->getSize().width(), -hitbox->getSize().height()) * 0.5;
        std::vector<QLineF> lines = {QLineF(a, b), QLineF(b, c), QLineF(c, d), QLineF(d, a)};
        std::vector<QPointF> _interPoints;
        for(const auto& line : lines) {
            QPointF* interPoint = new QPointF();
            auto inter = hitLine.intersects(line, interPoint);
            if(inter == QLineF::IntersectionType::BoundedIntersection) {
                _interPoints.push_back(*interPoint);
                delete interPoint;
            }
            else {
                delete interPoint;
            }
        }
        auto cmp = [&](QPointF a, QPointF b) {return (a - position).manhattanLength() > (b - position).manhattanLength();};
        std::sort(_interPoints.begin(), _interPoints.end(), cmp);
        interPoints.push_back(_interPoints[0]);
    }
    auto cmp = [&](QPointF a, QPointF b) {return (a - position).manhattanLength() < (b - position).manhattanLength();};
    std::sort(interPoints.begin(), interPoints.end(), cmp);
    return interPoints[std::min(int(interPoints.size()), pierce) - 1];
}

Hitscan* _pistol1(QPointF pos, QPointF dir)
{
    auto* res = new Hitscan;
    res->init(pos, dir, 3, 1.0, 0.1);
    return res;
}