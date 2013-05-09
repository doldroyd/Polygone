#ifndef RENDER_H
#define RENDER_H

#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_rotozoom.h>

#include "System.h"
#include "Physics.h"
#include "Position.h"

#define RENDER_PRIORITY 10 //placeholder
#define RENDER_NAME "Render" //placeholder

class RenderComponent : public Component
{
public:
	PositionComponent* positionCom;
	SDL_Surface *surface;
	int layer, width, height;
};

class RenderSystem : public System
{
	private:
    std::map<int, RenderComponent> render;
	SDL_Surface *screen;
	float cameraX;

	public:
		RenderSystem();
		~RenderSystem();

		virtual bool init();
		virtual void update(unsigned int delay);
		virtual void cleanup();

		virtual RenderComponent* getEntity(int EntityID);
		virtual void loadEntity(int EntityID, const YAML::Node &node);
		virtual bool removeEntity(int EntityID);
};

#endif //RENDER_H