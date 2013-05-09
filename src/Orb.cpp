#include "Orb.h"

OrbSystem::OrbSystem(): System(ORB_PRIORITY, ORB_NAME) {}
OrbSystem::~OrbSystem(){}

bool OrbSystem::init() {
    return true;
}
void OrbSystem::update(unsigned int delay){
}
void OrbSystem::cleanup(){}


OrbComponent* OrbSystem::getEntity(int EntityID){
	return &(orb[EntityID]);
}

void OrbSystem::loadEntity(int EntityID, const YAML::Node &node) {
    OrbComponent *o = getEntity(EntityID);
    node["size"] >> o->size;
}

bool OrbSystem::removeEntity(int EntityID){
	return (orb.erase(EntityID) == 1);
} 