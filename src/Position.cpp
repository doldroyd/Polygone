#include "Position.h"
PositionSystem::PositionSystem(Engine* e){}
PositionSystem::~PositionSystem(){}

void PositionSystem::init(){}
void PositionSystem::update(unsigned int delay){}
void PositionSystem::cleanup(){}


PositionComponent* PositionSystem::getEntity(int EntityID){
	PositionComponent* retval = &(position[EntityID]);
	return retval;
}


bool PositionSystem::removeEntity(int EntityID){
	bool retval;
	retval=((1==position.erase(EntityID))?true:false);
	return retval;
} 