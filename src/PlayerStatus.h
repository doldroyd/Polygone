#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include <map>
#include <SDL.h>

#include "System.h"

#define PLAYERSTATUS_PRIORITY 3 //placeholder
#define PLAYERSTATUS_NAME "Player Status"//placeholder

class PlayerStatusComponent : public Component
{
public:
  int size, color, scrollSpeed;
  bool overweight, micro, reverse;
};

class PlayerStatusSystem : public System
{
private:
	std::map<int, PlayerStatusComponent> characterStatus;

public:
	PlayerStatusSystem();
	~PlayerStatusSystem();
	
	virtual bool init(int EntityID);
	virtual void update(unsigned int delay);
	virtual void cleanup();

	virtual void sizeShift(int sizeMod, int EntityID);
	virtual void colorShift(int colorMod, int EntityID);
	virtual void scrollShift(int scrollMod, int EntityID);

	virtual PlayerStatusComponent* getEntity(int EntityID);
	virtual bool removeEntity(int EntityID);
};

#endif