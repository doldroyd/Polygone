#ifndef ORB_H
#define ORB_H

#include <map>
#include <SDL.h>


#include "System.h"

#define ORB_PRIORITY 0 //placeholder
#define ORB_NAME "Orb" //placeholder

class OrbComponent : public Component {
    public:
        int size;
};


class OrbSystem : public System
{
  private:
    std::map<int, OrbComponent> orb;
  
  public:
    OrbSystem();
    ~OrbSystem();

    virtual bool init();
    virtual void update(unsigned int delay);
    virtual void cleanup();

    virtual OrbComponent* getEntity(int EntityID);
    virtual void loadEntity(int EntityID, const YAML::Node &node);
    virtual bool removeEntity(int EntityID);

};


#endif //ORB_H