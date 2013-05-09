#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include <map>
#include <SDL.h>

#include "System.h"
#include "Render.h"

#define PLAYERSTATUS_PRIORITY 9
#define PLAYERSTATUS_NAME "PlayerStatus"

class CollisionComponent;

class PlayerStatusComponent : public Component {
public:
  RenderComponent* render;
  CollisionComponent* collision;
  int size;
};

class PlayerStatusSystem : public System
{
private:
	std::map<int, PlayerStatusComponent> playerStatus;

public:
	PlayerStatusSystem();
	~PlayerStatusSystem();
	
	virtual bool init();
	virtual void update(unsigned int delay);
	virtual void cleanup();

	//virtual void sizeShift(int sizeMod, int EntityID);
	//virtual void colorShift(int colorMod, int EntityID);
	//virtual void scrollShift(int scrollMod, int EntityID);

	virtual PlayerStatusComponent* getEntity(int EntityID);
    virtual void loadEntity(int EntityID, const YAML::Node &node);
	virtual bool removeEntity(int EntityID);
};

#include "Collision.h"

#endif