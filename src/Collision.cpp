#include "Collision.h"

CollisionSystem::CollisionSystem(): System(COLLISION_PRIORITY, COLLISION_NAME) {}
CollisionSystem::~CollisionSystem(){}

bool CollisionSystem::init() {
    return true;
}
void CollisionSystem::update(unsigned int delay){

}
void CollisionSystem::cleanup(){}


CollisionComponent* CollisionSystem::getEntity(int EntityID){
	CollisionComponent* retval = &(collision[EntityID]);
	return retval;
}

void CollisionSystem::loadEntity(int EntityID, const YAML::Node &node) {
    CollisionComponent *c = getEntity(EntityID);
}

bool CollisionSystem::removeEntity(int EntityID){
	bool retval;
	retval=(1==collision.erase(EntityID));
	return retval;
} 