#include "Group.h"

GroupSystem::GroupSystem(): System(GROUP_PRIORITY, GROUP_NAME) {}
GroupSystem::~GroupSystem(){}

bool GroupSystem::init() {
    return true;
}
void GroupSystem::update(unsigned int delay){}
void GroupSystem::cleanup(){}


GroupComponent* GroupSystem::getEntity(int EntityID){
	GroupComponent* retval = &(components[EntityID]);
	return retval;
}

void GroupSystem::loadEntity(int EntityID, const YAML::Node &node) {
    GroupComponent* c = getEntity(EntityID);
    node >> c->group;
}

bool GroupSystem::removeEntity(int EntityID){
	return components.erase(EntityID)==1;
}

void GroupSystem::deleteGroup(std::string group) {
    auto i = components.begin();
    while(i != components.end()) {
        if(i->second.group == group) {
            i = components.erase(i);
            Engine::instance().deleteEntity(i->first);
        }
        else i++;
    }
}