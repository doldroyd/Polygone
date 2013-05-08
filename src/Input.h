#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include "System.h"

#include "Position.h"
#include "Physics.h"

#define INPUT_PRIORITY 3 //placeholder
#define INPUT_NAME "Input" //placeholder

class InputComponent : public Component
{
	public:
		PhysicsComponent* pyhsicsCom;
		int mx, my;
};

class InputSystem : public System
{
	public:
		InputSystem();
		~InputSystem();

		virtual void update(unsigned int delay);
		virtual void cleanup();

		virtual InputComponent* getEntity(int EntityID);
		virtual bool removeEntity(int EntityID);

};
#endif