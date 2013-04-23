#include "Position.h"
PositionSystem(Engine* e){}
~PositionSystem(){}

void init(){}
void update(unsigned int delay){}
void cleanup(){}


PositionComponent* PositionSystem::getEntity(int EntityID){
	PositionComponent* retval = &position[EntityID];
	return retval;
}


virtual bool removeEntity(int EntityID){
	bool retval;
	reval=((1==position.erase(EntityID))?true:false;
	return retval;
} 