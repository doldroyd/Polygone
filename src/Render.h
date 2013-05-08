#ifndef RENDER_H
#define RENDER_H

#include <map>
#include "SDL.h"

#include "System.h"
#include "Physics.h"
#include "Position.h"

#define RENDER_PRIORITY 5 //placeholder
#define RENDER_NAME "Render" //placeholder

class RenderComponent : public Component
{
public:
  PositionComponent* positionCom;
  int xv, yv;
};

class RenderSystem : public System
{
	private:
    std::map<int, RenderComponent> render;

	public:
		Render();
		~Render();

		virtual bool init();
		virtual void update(unsigned int delay);
		virtual void load();
		virtual void run();
		virtual void cleanup();

		virtual RenderComponent* getEntity(int EntityID);
		virtual bool removeEntity(int EntityID);
};

#endif //RENDER_H