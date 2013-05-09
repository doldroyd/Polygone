#include "Position.h"

PositionSystem::PositionSystem(): System(POSITION_PRIORITY, POSITION_NAME) {}
PositionSystem::~PositionSystem(){}

bool PositionSystem::init() {
    return true;
}
void PositionSystem::update(unsigned int delay){
    for(auto &p : position) {
        p.second.oldx = p.second.x;
        p.second.oldy = p.second.y;
    }
}
void PositionSystem::cleanup(){}


PositionComponent* PositionSystem::getEntity(int EntityID){
	PositionComponent* retval = &(position[EntityID]);
	return retval;
}

void PositionSystem::loadEntity(int EntityID, const YAML::Node &node) {
    PositionComponent *c = getEntity(EntityID);
    node["x"] >> c->x;
    node["y"] >> c->y;
    c->oldx = c->x;
    c->oldy = c->y;
}

bool PositionSystem::removeEntity(int EntityID){
	bool retval;
	retval=(1==position.erase(EntityID));
	return retval;
} 