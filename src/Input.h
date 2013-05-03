#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include "System.h"

#include "Position.h"
#include "Physics.h"

class InputComponent : public Component
{
	PhysicsComponent* pyhsicsCom;
};

class InputSystem : public System
{
	public:
		int mx, my;
		InputSystem();
		~InputSystem();

		virtual void update(unsigned int delay);
		virtual void cleanup();

		virtual InputComponent* getEntity(int EntityID);
		virtual bool removeEntity(int EntityID);

};
#endif