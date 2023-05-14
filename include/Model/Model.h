#pragma once

#include <Model/EntityWrapper.h>
#include <vector>

class Model {
protected:
    std::vector<AbstractWrapper*> entities;
    // player object
    // spawner object
    // despawner object
    // painter object
public:
    void update(qreal deltaT);
    [[nodiscard("Model::getEntities() unused")]] std::vector<AbstractWrapper*> getEntities() const;

    void addEntity(AbstractWrapper* entity);
};