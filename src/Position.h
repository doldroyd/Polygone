#ifndef POSITION_H
//#define POSITION_H

#include <map>
#include <SDL.h>

#include "System.h"

class PositionComponent : public Component
{
  int x, y, oldx, oldy;
};


class PositionSystem : public System
{
  private:
    std::map<int, PositionComponent> position;
  
  public:
    PositionSystem(Engine* e);
    ~PositionSystem();

    virtual void init();
    virtual void update(unsigned int delay);
    virtual void cleanup();

    virtual PositionComponent* getEntity(int EntityID);
    virtual bool removeEntity(int EntityID);

    const std::string name;
    const int priority;
};
#endif //POSITION_H