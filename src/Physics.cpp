#include "Physics.h"
#include "Position.h"
PhysicsSystem::PhysicsSystem(Engine* e){}
PhysicsSystem::~PhysicsSystem(){}

void PhysicsSystem::init(){}
void PhysicsSystem::update(unsigned int delay) {
	for(auto physics : PhysicsComponent)
	{
		PositionComponent* positionCom.oldx = positionCom.x;
		PositionComponent* positionCom.oldy = positionCom.y;
		PositionComponent* positionCom.x = positionCom.x+xv*delay;
		PositionComponent* positionCom.y = positionCom.y+yv*delay;
	}
}
void cleanup(){}



PhysicsComponent* PhysicsSystem::getEntity(int EntityID){

	//insert
	bool newInsert = physics.insert(EntityID);
	if(newInsert==false){
		physics.positionCom = NULL;//PositionSystem::getEntity(EntityID);

	}
	PhysicsComponent* retval = &(physics[EntityID]);
	return retval;
}
bool PhysicsSystem::removeEntity(int EntityID){
	bool retval;
	retval=((1==physics.erase(EntityID))?true:false);
	return retval;
}
