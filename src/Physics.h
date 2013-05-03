#ifndef PHYSICS_H
#define PHYSICS_H

#include <map>
#include <SDL.h>

#include "System.h"
#include "Position.h"

#define PHYSICS_PRIORITY 2 //placeholder
#define PHYSICS_NAME "Physics" //placeholder

class PhysicsComponent : public Component
{
public:
  PositionComponent* positionCom;
  int xv, yv;
};

class PhysicsSystem : public System
{
  private:
    std::map<int, PhysicsComponent> physics;
  
  public:
    PhysicsSystem();
    ~PhysicsSystem();

    virtual bool init();
    virtual void update(unsigned int delay);
    virtual void cleanup();

    virtual PhysicsComponent* getEntity(int EntityID);
    virtual bool removeEntity(int EntityID);
};



#endif PHYSICS_H