#ifndef COLLISION_H
#define COLLISION_H

#include <map>
#include <vector>
#include <SDL.h>
#include <string>

#include "Engine.h"
#include "System.h"
#include "Position.h"
#include "PlayerStatus.h"
#include "Orb.h"

#define COLLISION_PRIORITY 3
#define COLLISION_NAME "Collision"

enum Collisions {player, wall, orb, edge, goal};

class CollisionComponent : public Component {
    public:
        PositionComponent* position;
        int width, height;
        Collisions type;
};


class CollisionSystem : public System
{
  private:
    std::map<int, CollisionComponent> collision;
    bool checkCollision(int Entity1, int Entity2);
    void consume(int Entity1, int Entity2);
    void moveback(int EntityID);
  
  public:
    CollisionSystem();
    ~CollisionSystem();

    virtual bool init();
    virtual void update(unsigned int delay);
    virtual void cleanup();

    virtual CollisionComponent* getEntity(int EntityID);
    virtual void loadEntity(int EntityID, const YAML::Node &node);
    virtual bool removeEntity(int EntityID);

};


#endif //COLLISION_H