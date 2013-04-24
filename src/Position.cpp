#include "Position.h"

PositionSystem::PositionSystem(): System(POSITION_PRIORITY, POSITION_NAME) {}
PositionSystem::~PositionSystem(){}

bool PositionSystem::init() {
    return true;
}
void PositionSystem::update(unsigned int delay){}
void PositionSystem::cleanup(){}


PositionComponent* PositionSystem::getEntity(int EntityID){
	PositionComponent* retval = &position[EntityID];
	return retval;
}


bool PositionSystem::removeEntity(int EntityID){
	bool retval;
	retval=(1==position.erase(EntityID))?true:false;
	return retval;
} 