#ifndef RENDER_H
#define RENDER_H

#include <map>
#include "SDL.h"
#include "SDL_image.h"

#include "System.h"
#include "Physics.h"
#include "Position.h"

#define RENDER_PRIORITY 5 //placeholder
#define RENDER_NAME "Render" //placeholder

class RenderComponent : public Component
{
public:
	PositionComponent* positionCom;
	SDL_Surface *surface = NULL;
};

class RenderSystem : public System
{
	private:
    std::map<int, RenderComponent> render;
	std::vector<System*> layers;
	SDL_Surface *screen = NULL;

	public:
		Render();
		~Render();

		bool registerLayer(System &s);

		virtual bool init();
		virtual void update(unsigned int delay);
		virtual void cleanup();

		virtual RenderComponent* getEntity(int EntityID);
		virtual bool removeEntity(int EntityID);
};

#endif //RENDER_H