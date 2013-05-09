#include "PlayerStatus.h"

PlayerStatusSystem::PlayerStatusSystem(): System(PLAYERSTATUS_PRIORITY, PLAYERSTATUS_NAME){}
PlayerStatusSystem::~PlayerStatusSystem(){}

/*bool PlayerStatusSystem::init(int EntityID){
	characterStatus[EntityID].size=15;
	characterStatus[EntityID].color=0;
	characterStatus[EntityID].scrollSpeed=11;
	characterStatus[EntityID].overweight=false;
	characterStatus[EntityID].micro=false;
	return true;
}*/

void PlayerStatusSystem::update(unsigned int delay){
    for(auto &ps : playerStatus) {
        if(ps.second.size <= 0) {
            //you are dead!
            Engine::instance().running = false;
        }
        ps.second.render->height = ps.second.size;
        ps.second.render->width = ps.second.size;
        ps.second.collision->height = ps.second.size;
        ps.second.collision->width = ps.second.size;
    }
}
/*
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
}*/

void PlayerStatusSystem::cleanup(){}

PlayerStatusComponent* PlayerStatusSystem::getEntity(int EntityID){
    auto i = playerStatus.find(EntityID);
    if(i == playerStatus.end()){
		playerStatus[EntityID].render = (RenderComponent*) Engine::instance().getSystem(RENDER_NAME)->getEntity(EntityID);
		playerStatus[EntityID].collision = (CollisionComponent*) Engine::instance().getSystem(COLLISION_NAME)->getEntity(EntityID);
	}
	return &(playerStatus[EntityID]);
}
bool PlayerStatusSystem::removeEntity(int EntityID) {
	return (playerStatus.erase(EntityID) == 1);
}

void PlayerStatusSystem::loadEntity(int EntityID, const YAML::Node &node) {
    PlayerStatusComponent *ps = getEntity(EntityID);
    node["size"] >> ps->size;
}

bool PlayerStatusSystem::init() {
    return true;
}