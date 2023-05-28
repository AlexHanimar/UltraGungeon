#include <Entities/Coin.h>
#include <Helpers/Helpers.h>
#include <QDebug>

Coin::Coin(QPointF pos, QPointF dir, QPointF velocity) : MovableEntity(1000000, {10, 10}, pos)
{
    Coin::setVelocity(normalize(dir) * 100 + velocity);
    state = Coin::STATE::ACTIVE;
    spawnAction = Coin::SPAWN_ACTION::NONE;
    lifeTime = maxLifeTime;
}

int Coin::getState() const
{
    return state;
}

int Coin::getSpawnAction() const
{
    return spawnAction;
}

void Coin::setState(int _state)
{
    switch(_state) {
        case Coin::STATE::ACTIVE:
            state = _state;
            break;
        case Coin::STATE::DEADCOIN:
            state = _state;
            break;
        case Coin::STATE::DESTROYED:
            state = _state;
            break;
        default:
            break;
    }
}

void Coin::setSpawnAction(int _spawnAction)
{
    switch(_spawnAction) {
        case Coin::SPAWN_ACTION::NONE:
            spawnAction = _spawnAction;
            break;
        case Coin::SPAWN_ACTION::PISTOL:
            spawnAction = _spawnAction;
            break;
        case Coin::SPAWN_ACTION::RAILGUN:
            spawnAction = _spawnAction;
            break;
        default:
            break;
    }
}

std::vector<QPointF> &Coin::getTargets()
{
    return targets;
}

void Coin::update(qreal deltaT)
{
    lifeTime -= deltaT;
    if(lifeTime < 0)
        setState(Coin::STATE::DESTROYED);
    moveBy(direction * speed * deltaT);
}

void Coin::addTarget(GameObject *obj, int prior)
{
    targetsObj.push_back({prior, obj});
}

void Coin::makeTargetList()
{
    auto cmp = [&](std::pair<int, GameObject *> a, std::pair<int, GameObject *> b) {
        if (a.first != b.first)
            return a.first < b.first;
        qreal d1 = (a.second->getAbsolutePosition() - getAbsolutePosition()).manhattanLength();
        qreal d2 = (b.second->getAbsolutePosition() - getAbsolutePosition()).manhattanLength();
        return d1 < d2;
    };
    std::sort(targetsObj.begin(), targetsObj.end(), cmp);
    for(auto [u, v] : targetsObj)
        targets.push_back(v->getAbsolutePosition());
}