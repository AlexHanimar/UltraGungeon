#pragma once

#include <MapGenerator/MapGenerator.h>
#include <MapGenerator/RoomGenerator.h>
#include <Model/Model.h>

class Level {
private:
    Model* model;
    MapGenerator* mapGen;
    RoomGenerator* roomGen;
public:
    explicit Level(Model* _model);
    void init();
    ~Level();
};