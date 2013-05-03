#ifndef GROUP_H
#define GROUP_H

#include <map>
#include <vector>

#include "System.h"
#include "Engine.h"

#define GROUP_PRIORITY 0 //do not call update
#define GROUP_NAME "Group" //placeholder

class GroupComponent : public Component {
    public:
        std::string group;
};


class GroupSystem : public System
{
  private:
    std::map<int, GroupComponent> components;
    std::map<std::string, std::vector<int>> groups;
  
  public:
    GroupSystem();
    ~GroupSystem();

    virtual bool init();
    virtual void update(unsigned int delay);
    virtual void cleanup();

    virtual GroupComponent* getEntity(int EntityID);
    virtual void loadEntity(int EntityID, const YAML::Node &node);
    virtual bool removeEntity(int EntityID);

    void deleteGroup(std::string group);

};


#endif //GROUP_H