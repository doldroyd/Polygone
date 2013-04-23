#ifndef PHYSICS_H
#define PHYSICS_H


#include "SDL.h"

#include "Engine.h"
#include "System.h"

class VelocityComponent : public Component
{
  int x, y;
};

class Physics
{
  private:

  public:
  Physics(void);
  ~Physics(void);

void PositUpdate(deltaTime, int vx, int vy, ENTITY);
}



#endif PHYSICS_H