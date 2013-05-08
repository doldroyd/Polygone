#ifndef COLLISION_H
#define COLLISION_H

#include <map>
#include <SDL.h>


#include "System.h"

#define COLLISION_PRIORITY 3
#define COLLISION_NAME "Collision"

class CollisionComponent : public Component {
    public:
        int width, height;
};


class CollisionSystem : public System
{
  private:
    std::map<int, CollisionComponent> collision;
  
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