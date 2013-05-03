#include "PlayerStatus.h"

PlayerStatusSystem::PlayerStatusSystem(): System(PLAYERSTATUS_PRIORITY, PLAYERSTATUS_NAME){}
PlayerStatusSystem::~PlayerStatusSystem(){}

bool PlayerStatusSystem::init(int EntityID){
	characterStatus[EntityID].size=15;
	characterStatus[EntityID].color=0;
	characterStatus[EntityID].scrollSpeed=11;
	characterStatus[EntityID].overweight=false;
	characterStatus[EntityID].micro=false;
	return true;
}

void PlayerStatusSystem::update(unsigned int delay){
}

void PlayerStatusSystem::sizeShift(int sizeMod, int EntityID){
	characterStatus[EntityID].size+=sizeMod;
	characterStatus[EntityID].overweight=(characterStatus[EntityID].size>=30);
	if(characterStatus[EntityID].size<=0){
		characterStatus[EntityID].micro=true;
	}
}
void PlayerStatusSystem::colorShift(int colorMod, int EntityID){
	characterStatus[EntityID].color=colorMod;
}
void PlayerStatusSystem::scrollShift(int scrollMod, int EntityID){
	characterStatus[EntityID].scrollSpeed+=scrollMod;
	characterStatus[EntityID].reverse=(characterStatus[EntityID].scrollSpeed>=0);
}

void PlayerStatusSystem::cleanup(){}

PlayerStatusComponent* PlayerStatusSystem::getEntity(int EntityID){
	PlayerStatusComponent* retval = &(characterStatus[EntityID]);
	return retval;
}
bool PlayerStatusSystem::removeEntity(int EntityID){
	bool retval;
	retval=(1==characterStatus.erase(EntityID));
	return retval;
}