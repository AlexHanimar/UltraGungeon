#include <Model/Level.h>
#include <QDebug>

Level::Level(Model *_model)
{
    model = _model;
    mapGen = new MapGenerator(time(NULL));
    roomGen = new RoomGenerator();
}

void Level::init()
{
    QSize mapSizeRooms(6, 6);
    QSize roomSizeBlocks(20, 20);
    QSize blockSize(50, 50);

    QSize roomSize(blockSize.width() * roomSizeBlocks.width(), blockSize.height() * roomSizeBlocks.height());
    QSizeF triggerSize(roomSize.width() - blockSize.width() * 4, roomSize.height() - blockSize.height() * 4);

    QPointF topLeftCorner(10000, 10000);
    QPointF roomCenterOffset(qreal(roomSize.width()) * 0.5, qreal(roomSize.height()) * 0.5);
    QPointF blockCenterOffset(qreal(blockSize.width()) * 0.5, qreal(blockSize.height()) * 0.5);

    qreal wallOffset = 6.0;

    auto mapGrid = mapGen->generateMap(mapSizeRooms.width(), mapSizeRooms.height());
    QPointF mapRowStart(topLeftCorner);
    QPointF mapRowShift(0, roomSize.height());
    for(int mapRow = 0;mapRow < mapSizeRooms.height();mapRow++) {
        QPointF roomTopLeftCorner = mapRowStart;
        QPointF mapColShift(roomSize.width(), 0);
        for(int mapCol = 0;mapCol < mapSizeRooms.width();mapCol++) {

            if(mapGrid[mapRow][mapCol] == ROOM_TYPE::NONE) {
                roomTopLeftCorner += mapColShift;
                continue;
            }
            if(mapGrid[mapRow][mapCol] == ROOM_TYPE::ENTRANCE) {
                auto* player = new PlayerEntity(0, {10, 10}, roomTopLeftCorner + roomCenterOffset);
                player->init();
                model->setPlayerEntity(player);
            }
            else {
                auto* trigger = new Trigger(triggerSize, roomTopLeftCorner + roomCenterOffset);
                model->addTrigger(wrap(trigger));
            }

            int roomMask = 0;
            if(mapRow > 0 && mapGrid[mapRow - 1][mapCol] != ROOM_TYPE::NONE)
                roomMask |= CONNECT::UP;
            if(mapRow + 1 < mapSizeRooms.height() && mapGrid[mapRow + 1][mapCol] != ROOM_TYPE::NONE)
                roomMask |= CONNECT::DOWN;
            if(mapCol > 0 && mapGrid[mapRow][mapCol - 1] != ROOM_TYPE::NONE)
                roomMask |= CONNECT::LEFT;
            if(mapCol + 1 < mapSizeRooms.width() && mapGrid[mapRow][mapCol + 1] != ROOM_TYPE::NONE)
                roomMask |= CONNECT::RIGHT;
            auto roomGrid = roomGen->generateRoom(roomSizeBlocks.height(), roomSizeBlocks.width(), roomMask);
            QPointF roomRowStart = roomTopLeftCorner;
            QPointF roomRowShift(0, blockSize.height());
            for(int roomRow = 0;roomRow < roomSizeBlocks.height();roomRow++) {
                QPointF blockTopLeftCorner = roomRowStart;
                QPointF roomColShift(blockSize.width(), 0);
                for (int roomCol = 0; roomCol < roomSizeBlocks.width(); roomCol++) {
                    QPointF blockCenter = blockTopLeftCorner + blockCenterOffset;
                    if(roomGrid[roomRow][roomCol] == BLOCK_TYPE::WALL)
                        model->addStaticEntity(wrap(new Wall(blockSize, wallOffset, wallOffset, blockCenter)));
                    if(roomGrid[roomRow][roomCol] == BLOCK_TYPE::DOOR)
                        model->addStaticEntity(wrap(new Door(blockSize, wallOffset, wallOffset, blockCenter)));
                    blockTopLeftCorner += roomColShift;
                }
                roomRowStart += roomRowShift;
            }
            roomTopLeftCorner += mapColShift;
        }
        mapRowStart += mapRowShift;
    }
    model->setDifficulty(4);
}

Level::~Level()
{
    delete mapGen;
    delete roomGen;
}