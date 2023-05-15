#pragma once

#include <Model/EntityWrapper.h>
#include <vector>

enum INPUT {
    KEY_W = 0b000000000001,
    KEY_A = 0b000000000010,
    KEY_S = 0b000000000100,
    KEY_D = 0b000000001000
};

class Model {
protected:
    int inputMask;
    std::vector<AbstractWrapper*> entities;
    // player object
    // spawner object
    // despawner object
    // painter object
public:
    void update(qreal deltaT);
    [[nodiscard("Model::getEntities() unused")]] std::vector<AbstractWrapper*> getEntities() const;

    void addEntity(AbstractWrapper* entity);

    void setInputMask(int _inputMask);
};