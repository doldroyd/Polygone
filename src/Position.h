#ifndef POSITION_H
#define POSITION_H

#include <map>
#include <SDL.h>

#include "System.h"

#define POSITION_PRIORITY 1 //placeholder
#define POSITION_NAME "Position" //placeholder

class PositionComponent : public Component
{
  int x, y, oldx, oldy;
};


class PositionSystem : public System
{
  private:
    std::map<int, PositionComponent> position;
  
  public:
    PositionSystem();
    ~PositionSystem();

    virtual bool init();
    virtual void update(unsigned int delay);
    virtual void cleanup();

    virtual PositionComponent* getEntity(int EntityID);
    virtual bool removeEntity(int EntityID);

};
#endif //POSITION_H