#include <Model/Model.h>
#include <algorithm>
#include <QDebug>
#include <iostream>

// Time interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractInteraction *Time_Wrapper::generateInteraction()
{
    auto* inter = new Time_Interaction;
    inter->first = this;
    return inter;
}

void Time_Wrapper::accept(AbstractInteraction *interaction) {}

void Time_Interaction::apply(Wall_Wrapper *second) {}
void Time_Interaction::apply(Door_Wrapper *second) {}
void Time_Interaction::apply(MovableEntity_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(PlayerEntity_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(Projectile_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(EnemyFilth_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(EnemyAndre_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(Trigger_Wrapper *second) {}
void Time_Interaction::apply(Hitscan_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(PistolHitscan_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(BlueRailcannonHitscan_Wrapper *second)
{
    second->item->update(*first->item);
}
void Time_Interaction::apply(AndreBallProjectile_Wrapper *second)
{
    second->item->update(*first->item);
}

Time_Wrapper::~Time_Wrapper() {delete item;}
Time_Interaction::~Time_Interaction() {}

AbstractWrapper* wrap(qreal *timeItem) {auto wrapper = new Time_Wrapper; wrapper->item = timeItem; return wrapper;}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Input interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractInteraction *Input_Wrapper::generateInteraction()
{
    auto* inter = new Input_Interaction;
    inter->first = this;
    return inter;
}

void Input_Wrapper::accept(AbstractInteraction *interaction) {}

void Input_Interaction::apply(Wall_Wrapper *second) {}
void Input_Interaction::apply(Door_Wrapper *second) {}
void Input_Interaction::apply(MovableEntity_Wrapper *second) {}
void Input_Interaction::apply(PlayerEntity_Wrapper *second)
{
    // physics update
    if(second->item->getState() != PlayerEntity::STATE::DASHING) {
        QPointF dir(0, 0);
        if (*first->item & INPUT::KEY_W)
            dir += {0, -1};
        if (*first->item & INPUT::KEY_A)
            dir += {-1, 0};
        if (*first->item & INPUT::KEY_S)
            dir += {0, 1};
        if (*first->item & INPUT::KEY_D)
            dir += {1, 0};
        second->item->setDirection(dir);
        if (*first->item & INPUT::KEY_DASH) {
            if (second->item->getState() == PlayerEntity::STATE::DEFAULT)
                second->item->setState(PlayerEntity::STATE::DASHING);
        }
        second->item->setSpeed(second->item->getMaxSpeed());
    }
    // parry update
    if(*first->item & INPUT::KEY_F) {
        second->item->setParryState(PlayerEntity::PARRY_STATE::PARRY_ACTIVE);
    }

    // weapon update
    if(*first->item & INPUT::KEY_1)
        second->item->setWeapon(PlayerEntity::WEAPON::PISTOL);
    else if(*first->item & INPUT::KEY_2)
        second->item->setWeapon(PlayerEntity::WEAPON::SHOTGUN);
    else if(*first->item & INPUT::KEY_3)
        second->item->setWeapon(PlayerEntity::WEAPON::RAILGUN);

    second->item->setSpawnDirection(*first->mouseDir);
    if(second->item->getWeaponState() == PlayerEntity::WEAPON_STATE::READY) {
        if(!(*first->item & INPUT::MOUSE_1) && !(*first->item & INPUT::MOUSE_2)) {
            goto _NO_SPAWN_ACTION;
        }
        switch(second->item->getWeapon()) {
            case PlayerEntity::WEAPON::PISTOL:
                if (*first->item & INPUT::MOUSE_1)
                    second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::PISTOL_1);
                else if (*first->item & INPUT::MOUSE_2)
                    second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::PISTOL_2);
                break;
            case PlayerEntity::WEAPON::SHOTGUN:
                if (*first->item & INPUT::MOUSE_1)
                    second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::SHOTGUN_1);
                else if (*first->item & INPUT::MOUSE_2)
                    second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::SHOTGUN_2);
                break;
            case PlayerEntity::WEAPON::RAILGUN:
                if (*first->item & INPUT::MOUSE_1)
                    second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::RAILGUN_1);
                else if (*first->item & INPUT::MOUSE_2)
                    second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::RAILGUN_2);
                break;
            default:
                break;
        }
    }
    else {
        _NO_SPAWN_ACTION:
        if(second->item->getSpawnAction() == PlayerEntity::SPAWN_ACTION::PARRY)
            second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::PARRY);
        else
            second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::NONE);
    }
}
void Input_Interaction::apply(Projectile_Wrapper *second) {}
void Input_Interaction::apply(EnemyFilth_Wrapper *second) {}
void Input_Interaction::apply(EnemyAndre_Wrapper *second) {}
void Input_Interaction::apply(Trigger_Wrapper *second) {}
void Input_Interaction::apply(Hitscan_Wrapper *second) {}
void Input_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Input_Interaction::apply(BlueRailcannonHitscan_Wrapper *second) {}
void Input_Interaction::apply(AndreBallProjectile_Wrapper *second) {}

Input_Wrapper::~Input_Wrapper()
{
    item = nullptr;
    delete item;
    mouseDir = nullptr;
    delete mouseDir;
}
Input_Interaction::~Input_Interaction()
{
    //delete first;
}

AbstractWrapper* wrap(int *inputItem, QPointF* mouseItem)
{
    auto* wrapper = new Input_Wrapper;
    wrapper->item = inputItem;
    wrapper->mouseDir = mouseItem;
    return wrapper;
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Spawn interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractInteraction *Spawn_Wrapper::generateInteraction()
{
    auto* inter = new Spawn_Interaction;
    inter->first = this;
    return inter;
}

void Spawn_Wrapper::accept(AbstractInteraction *interaction) {}

void Spawn_Interaction::apply(Wall_Wrapper *second) {}
void Spawn_Interaction::apply(Door_Wrapper *second) {}
void Spawn_Interaction::apply(MovableEntity_Wrapper *second) {}
void Spawn_Interaction::apply(PlayerEntity_Wrapper *second)
{
    switch(second->item->getSpawnAction()) {
        case PlayerEntity::SPAWN_ACTION::NONE:
            break;
        case PlayerEntity::SPAWN_ACTION::PISTOL_1:
        {
            second->item->setWeaponState(PlayerEntity::WEAPON_STATE::RELOADING);
            auto* hitscan = new PistolHitscan(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            //auto* projectile = pistol1(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            first->item->addHitscan(wrap(hitscan));
        }
            break;
        case PlayerEntity::SPAWN_ACTION::PISTOL_2:
        {
            second->item->setWeaponState(PlayerEntity::WEAPON_STATE::RELOADING);
            auto* projectile = pistol2(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            first->item->addDynamicEntity(wrap(projectile));
        }
            break;
        case PlayerEntity::SPAWN_ACTION::SHOTGUN_1:
        {
            second->item->setWeaponState(PlayerEntity::WEAPON_STATE::RELOADING);
            auto projectiles = shotgun1(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            for(auto* projectile : projectiles)
                first->item->addDynamicEntity(wrap(projectile));
        }
            break;
        case PlayerEntity::SPAWN_ACTION::SHOTGUN_2:
        {
            second->item->setWeaponState(PlayerEntity::WEAPON_STATE::RELOADING);
            auto* projectile = shotgun2(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            first->item->addDynamicEntity(wrap(projectile));
        }
            break;
        case PlayerEntity::SPAWN_ACTION::RAILGUN_1:
        {
            second->item->setWeaponState(PlayerEntity::WEAPON_STATE::RELOADING);
            auto* hitscan = new BlueRailcannonHitscan(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            first->item->addHitscan(wrap(hitscan));
        }
            break;
        case PlayerEntity::SPAWN_ACTION::RAILGUN_2:
        {
            second->item->setWeaponState(PlayerEntity::WEAPON_STATE::RELOADING);
            auto* projectile = railgun2(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            first->item->addDynamicEntity(wrap(projectile));
        }
            break;
        case PlayerEntity::SPAWN_ACTION::PARRY:
        {
            auto* projectile = andreBall(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            second->item->setSpawnAction(PlayerEntity::SPAWN_ACTION::NONE);
            projectile->setTeam(TEAM::PLAYER);
            first->item->addDynamicEntity(wrap(projectile));
        }
        default:
            break;
    }
}
void Spawn_Interaction::apply(Projectile_Wrapper *second) {}
void Spawn_Interaction::apply(EnemyFilth_Wrapper *second) {}
void Spawn_Interaction::apply(EnemyAndre_Wrapper *second)
{
    switch(second->item->getSpawnAction()) {
        case EnemyAndre::SPAWN_ACTION::NONE:
            break;
        case EnemyAndre::SPAWN_ACTION::BALL:
        {
            auto* projectile = new AndreBallProjectile(second->item->getAbsolutePosition(), second->item->getSpawnDirection());
            first->item->addDynamicEntity(wrap(projectile));
            second->item->setSpawnAction(EnemyAndre::SPAWN_ACTION::NONE);
        }
            break;
        default:
            break;
    }
}
void Spawn_Interaction::apply(Trigger_Wrapper *second) {}
void Spawn_Interaction::apply(Hitscan_Wrapper *second) {}
void Spawn_Interaction::apply(PistolHitscan_Wrapper *second) {}
void Spawn_Interaction::apply(BlueRailcannonHitscan_Wrapper *second) {}
void Spawn_Interaction::apply(AndreBallProjectile_Wrapper *second) {}

AbstractWrapper* wrap(Model* item) {auto wrapper = new Spawn_Wrapper; wrapper->item = item; return wrapper;}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// Spawn interaction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AbstractInteraction *Despawn_Wrapper::generateInteraction()
{
    auto* inter = new Despawn_Interaction;
    inter->first = this;
    return inter;
}

void Despawn_Wrapper::accept(AbstractInteraction *interaction) {}

void Despawn_Interaction::apply(Wall_Wrapper *second) {}
void Despawn_Interaction::apply(Door_Wrapper *second) {}
void Despawn_Interaction::apply(MovableEntity_Wrapper *second) {}
void Despawn_Interaction::apply(PlayerEntity_Wrapper *second) {}
void Despawn_Interaction::apply(Projectile_Wrapper *second)
{
    if(second->item->getState() == Projectile::STATE::DESTROYED) {
        delete second->item;
        second->markedForDeletion = true;
    }
}
void Despawn_Interaction::apply(EnemyFilth_Wrapper *second)
{
    if(second->item->getHealth() <= 0) {
        delete second->item;
        second->markedForDeletion = true;
    }
}
void Despawn_Interaction::apply(EnemyAndre_Wrapper *second)
{
    if(second->item->getHealth() <= 0) {
        delete second->item;
        second->markedForDeletion = true;
    }
}
void Despawn_Interaction::apply(Trigger_Wrapper *second) {}
void Despawn_Interaction::apply(Hitscan_Wrapper *second)
{
    if(second->item->getState() == Hitscan::STATE::DESTROYED) {
        delete second->item;
        second->markedForDeletion = true;
    }
}
void Despawn_Interaction::apply(PistolHitscan_Wrapper *second)
{
    if(second->item->getState() == Hitscan::STATE::DESTROYED) {
        delete second->item;
        second->markedForDeletion = true;
    }
}
void Despawn_Interaction::apply(BlueRailcannonHitscan_Wrapper *second)
{
    if(second->item->getState() == Hitscan::STATE::DESTROYED) {
        delete second->item;
        second->markedForDeletion = true;
    }
}
void Despawn_Interaction::apply(AndreBallProjectile_Wrapper *second)
{
    if(second->item->getState() == AndreBallProjectile::STATE::DESTROYED) {
        delete second->item;
        second->markedForDeletion = true;
    }
}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Model::Model()
    : spawnWrapper(wrap(this))
    , despawnWrapper(new Despawn_Wrapper)
    , inputWrapper(wrap(&inputMask, &mouseDirection)) {}

void Model::update(qreal deltaT)
{
    // triggers
    for(auto* trigger : triggers) {
        interact(trigger, playerEntity);
        for(auto* entity : dynamicEntities)
            interact(trigger, entity);
        for(auto* entity : staticEntities)
            interact(trigger, entity);
    }

    // updating input
    interact(inputWrapper, playerEntity);

    // spawning entities
    interact(spawnWrapper, playerEntity);
    for(auto* entity : staticEntities)
        interact(spawnWrapper, entity);
    for(auto* entity : dynamicEntities)
        interact(spawnWrapper, entity);

    // paired interactions
    for(auto* staticEntity : staticEntities) {
        for(auto* dynamicEntity : dynamicEntities) {
            interact(staticEntity, dynamicEntity);
            interact(dynamicEntity, staticEntity);
        }
    }
    for(auto* entity1 : dynamicEntities) {
        for(auto* entity2 : dynamicEntities) {
            if(entity1 != entity2)
                interact(entity1, entity2);
        }
    }
    for(auto* hitscan : hitscans) {
        for(auto* entity : dynamicEntities)
            interact(hitscan, entity);
        for(auto* entity : staticEntities)
            interact(hitscan, entity);
    }

    // player interactions
    for(auto* entity : dynamicEntities) {
        interact(playerEntity, entity);
        interact(entity, playerEntity);
    }
    for(auto* entity : staticEntities) {
        interact(entity, playerEntity);
    }

    // self update
    for(auto* hitscan : hitscans)
        interact(hitscan, hitscan);

    // time update
    auto* timeWrapper = wrap(new qreal(deltaT));
    for(auto* entity : dynamicEntities) {
        interact(timeWrapper, entity);
    }
    for(auto* entity : staticEntities) {
        interact(timeWrapper, entity);
    }
    for(auto* hitscan : hitscans) {
        interact(timeWrapper, hitscan);
    }
    interact(timeWrapper, playerEntity);
    delete timeWrapper;

    // despawning entities
    for(auto* entity : dynamicEntities)
        interact(despawnWrapper, entity);
    for(auto* entity : hitscans)
        interact(despawnWrapper, entity);
    std::erase_if(dynamicEntities, [](AbstractWrapper* w){return w->markedForDeletion;});
    std::erase_if(hitscans, [](AbstractWrapper* w){return w->markedForDeletion;});
}

void Model::addStaticEntity(AbstractWrapper *entity)
{
    staticEntities.push_back(entity);
}

void Model::addDynamicEntity(AbstractWrapper *entity)
{
    dynamicEntities.push_back(entity);
}

void Model::addTrigger(AbstractWrapper *trigger)
{
    triggers.push_back(trigger);
}

void Model::addHitscan(AbstractWrapper *hitscan)
{
    hitscans.push_back(hitscan);
}

std::vector<AbstractWrapper *> &Model::getStaticEntities()
{
    return staticEntities;
}

std::vector<AbstractWrapper *> &Model::getDynamicEntities()
{
    return dynamicEntities;
}

std::vector<AbstractWrapper *> &Model::getTriggers()
{
    return triggers;
}

std::vector<AbstractWrapper *> &Model::getHitscans()
{
    return hitscans;
}

void Model::setInputMask(int _inputMask)
{
    inputMask = _inputMask;
}

void Model::setMouseDirection(QPointF _mouseDirection)
{
    mouseDirection = _mouseDirection;
}

AbstractWrapper *Model::getPlayerEntity() const
{
    return playerEntity;
}

void Model::setPlayerEntity(PlayerEntity *player)
{
    playerEntity = wrap(player);
}