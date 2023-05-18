#include <Model/Model.h>
#include <algorithm>
#include <QDebug>

void Model::update(qreal deltaT)
{
    // self update
    for(auto* entity : entities)
        interact(entity, entity);
    // hard collisions
    for(auto* entity1 : entities) {
        for(auto* entity2 : entities)
            interact(entity1, entity2);
    }
    // time update
    auto* timeWrapper = wrap(new qreal(deltaT));
    for(auto* entity : entities) {
        interact(timeWrapper, entity);
    }
    std::erase_if(entities, [](AbstractWrapper* w){return (w == nullptr);});
}

std::vector<AbstractWrapper *> Model::getEntities() const
{
    return entities;
}

void Model::addEntity(AbstractWrapper *entity)
{
    entities.push_back(entity);
}

void Model::setInputMask(int _inputMask)
{
    inputMask = _inputMask;
}
