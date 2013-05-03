#include "Physics.h"
#include "Position.h"
PhysicsSystem::PhysicsSystem(Engine* e){}
PhysicsSystem::~PhysicsSystem(){}

void PhysicsSystem::init(){}
void PhysicsSystem::update(unsigned int delay) {
	for(auto physics : PhysicsComponent)
	{
		/* PositionComponent* */ physics.positionCom.oldx = positionCom.x;
		/* PositionComponent* */ physics.positionCom.oldy = positionCom.y;
		/* PositionComponent* */ physics.positionCom.x = positionCom.x+physics.xv*delay;
		/* PositionComponent* */ physics.positionCom.y = positionCom.y+physics.yv*delay;
	}
}
void cleanup(){}



PhysicsComponent* PhysicsSystem::getEntity(int EntityID){

	//insert
	bool newInsert = physics.insert(EntityID);
	if(newInsert==false){
		physics.positionCom = PositionSystem::getEntity(EntityID);

	}
	PhysicsComponent* retval = &(physics[EntityID]);
	return retval;
}
bool PhysicsSystem::removeEntity(int EntityID){
	bool retval;
	retval=((1==physics.erase(EntityID))?true:false);
	return retval;
}
