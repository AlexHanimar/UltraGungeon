#include <Entities/Hitscan.h>
#include <QLineF>
#include <QPolygonF>
#include <QDebug>

Hitscan::Hitscan(qreal _damage, int _pierce, QPointF _pos, QPointF _dir, qreal _lifetime, TEAM _team)
    : damage(_damage)
    , pierce(_pierce)
    , position(_pos)
    , direction(normalize(_dir))
    , maxLifeTime(_lifetime)
    , team(_team)
    , state(Hitscan::STATE::CHARGED) {}

int Hitscan::getState() const
{
    return state;
}

void Hitscan::setState(int _state)
{
    switch(_state) {
        case Hitscan::STATE::CHARGED:
            state = _state;
            break;
        case Hitscan::STATE::DEFAULT:
            state = _state;
            lifeTime = maxLifeTime;
            {
                if (pierced.empty()) {
                    endpoint = position + direction * 100000.0;
                    break;
                }
                std::vector<QPointF> interPoints;
                QLineF hitLine(position, position + direction * 100000.0);
                for (auto *hitbox: pierced) {
                    QPointF a = hitbox->getAbsolutePosition() +
                                QPointF(-hitbox->getSize().width(), -hitbox->getSize().height()) * 0.5;
                    QPointF b = hitbox->getAbsolutePosition() +
                                QPointF(-hitbox->getSize().width(), hitbox->getSize().height()) * 0.5;
                    QPointF c = hitbox->getAbsolutePosition() +
                                QPointF(hitbox->getSize().width(), hitbox->getSize().height()) * 0.5;
                    QPointF d = hitbox->getAbsolutePosition() +
                                QPointF(hitbox->getSize().width(), -hitbox->getSize().height()) * 0.5;
                    std::vector<QLineF> lines = {QLineF(a, b), QLineF(b, c), QLineF(c, d), QLineF(d, a)};
                    std::vector<QPointF> _interPoints;
                    for (const auto &line: lines) {
                        QPointF *interPoint = new QPointF();
                        auto inter = hitLine.intersects(line, interPoint);
                        if (inter == QLineF::IntersectionType::BoundedIntersection) {
                            _interPoints.push_back(*interPoint);
                            delete interPoint;
                        } else {
                            delete interPoint;
                        }
                    }
                    auto cmp = [&](QPointF a, QPointF b) {
                        return (a - position).manhattanLength() < (b - position).manhattanLength();
                    };
                    std::sort(_interPoints.begin(), _interPoints.end(), cmp);
                    interPoints.push_back(_interPoints[0]);
                }
                if(interPoints.size() < pierce) {
                    endpoint = position + direction * 100000.0;
                    break;
                }
                auto cmp = [&](QPointF a, QPointF b) {
                    return (a - position).manhattanLength() < (b - position).manhattanLength();
                };
                std::sort(interPoints.begin(), interPoints.end(), cmp);
                std::sort(pierced.begin(), pierced.end(),
                    [&](AbstractHitbox* a, AbstractHitbox* b)
                    {
                        return (a->getAbsolutePosition() - position).manhattanLength() < (b->getAbsolutePosition() - position).manhattanLength();
                    }
                );
                endpoint = interPoints[pierce - 1];
            }
            break;
        case Hitscan::STATE::DISCHARGED:
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
    if(state == Hitscan::STATE::DISCHARGED) {
        lifeTime -= deltaT;
        if (lifeTime < 0)
            setState(Hitscan::STATE::DESTROYED);
    }
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
        auto* interPoint = new QPointF();
        auto inter = hitLine.intersects(line, interPoint);
        if(inter == QLineF::IntersectionType::BoundedIntersection) {
            pierced.push_back(hitbox);
            delete interPoint;
            return;
        }
        delete interPoint;
    }
}

QPointF Hitscan::getEndpoint() const
{
    return endpoint;
}

bool Hitscan::pierces(AbstractHitbox *hitbox) const
{
    for(int i = 0;i < std::min(int(pierced.size()), pierce);i++) {
        if(pierced[i] == hitbox)
            return true;
    }
    return false;
}