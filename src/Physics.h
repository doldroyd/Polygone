#ifndef PHYSICS_H
#define PHYSICS_H

#include <map>
#include <SDL.h>

#include "System.h"
#include "Position.h"

class PhysicsComponent : public Component
{
  PositionComponent* positionCom;
  int xv, yv;
};

class PhysicsSystem : public System
{
  private:
    std::map<int, PhysicsComponent> physics;
  
  public:
    PhysicsSystem(Engine* e);
    ~PhysicsSystem();

    virtual void init();
    virtual void update(unsigned int delay);
    virtual void cleanup();

    virtual PhysicsComponent* getEntity(int EntityID);
    virtual bool removeEntity(int EntityID);

    const std::string name;
    const int priority;
};



#endif PHYSICS_H