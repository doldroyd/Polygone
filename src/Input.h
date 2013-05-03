#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include "System.h"

#include "Position.h"
#include "Physics.h"

#define INPUT_PRIORITY
#define INPUT_NAME "Input"
class InputComponent : public Component
{
	PhysicsComponent* pyhsicsCom;
};

class InputSystem : public System
{
	public:
		//not sure if this is correct
		SDL_Event *events;
		int numevents;
		SDL_eventaction action;
		Uint32 mask;
		///////////////////////////

		InputSystem();
		~InputSystem();

		virtual void update(unsigned int delay);
		virtual void cleanup();

		virtual InputComponent* getEntity(int EntityID);
		virtual bool removeEntity(int EntityID);

		void update(unsigned int delay);
};
#endif