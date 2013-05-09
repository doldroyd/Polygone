#include "Render.h"
#include "Physics.h"
#include "Position.h"
#include "Engine.h"

RenderSystem::RenderSystem(): System(RENDER_PRIORITY, RENDER_NAME){}
RenderSystem::~RenderSystem() {}

bool compare(RenderComponent *i, RenderComponent *j) {
    return i->layer < j->layer;
}


//Load image function
SDL_Surface *load_image( std::string filename ) 
{ 
	//Temporary storage for the image that's loaded 
	SDL_Surface* loadedImage = NULL; 
	//The optimized image that will be used 
	SDL_Surface* optimizedImage = NULL;
	//Load the image 
	loadedImage = IMG_Load( filename.c_str() );

		//If nothing went wrong in loading the image 
		if( loadedImage != NULL ) { 
			//Create an optimized image 
			optimizedImage = SDL_DisplayFormat( loadedImage ); 
			//Free the old image 
			SDL_FreeSurface( loadedImage ); 
		}
	//Return the optimized image 
	return optimizedImage; 
}


//Apply to surface function
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) { 
	//Make a temporary rectangle to hold the offsets 
	SDL_Rect offset; 
	//Give the offsets to the rectangle 
	offset.x = x; 
	offset.y = y;
		
	//Blit the surface
	SDL_BlitSurface( source, NULL, destination, &offset );
}

bool RenderSystem::init(void) {
	//Start SDL 
	SDL_InitSubSystem( SDL_INIT_VIDEO);
	//Set up screen 
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_DOUBLEBUF|SDL_HWSURFACE);

	cameraX = 0;

	return true;

}
void RenderSystem::update(unsigned int delay) {

	//Move camera 
	cameraX += 20/static_cast<float>(delay); 

	std::vector<RenderComponent*> r;
	for(auto p : render)
	{
		r.push_back(&p.second);
	}
	std::sort(r.begin(), r.end(), compare);
	for(auto p : r) {
			 
		//Apply image
		apply_surface( p->positionCom->x - static_cast<int>(cameraX), p->positionCom->y, p->surface, screen );

		SDL_Flip(screen);
	}
}

RenderComponent* RenderSystem::getEntity(int EntityID){

	//insert
    auto i = render.find(EntityID);
	if(i == render.end()){
		render[EntityID].positionCom = (PositionComponent*) Engine::instance().getSystem(POSITION_NAME)->getEntity(EntityID);
	}
	RenderComponent* retval = &(render[EntityID]);
	return retval;
}

void RenderSystem::loadEntity(int EntityID, const YAML::Node &node) {
    RenderComponent *c = getEntity(EntityID);
    node["layer"] >> c->layer;
	std::string temp;
    node["file"] >> temp;
	c->surface = load_image(temp);

}
bool RenderSystem::removeEntity(int EntityID){
	RenderComponent *c = getEntity(EntityID);
	SDL_FreeSurface( c->surface );

	bool retval;
	retval=((1==render.erase(EntityID))?true:false);
	return retval;
}

void RenderSystem::cleanup(){}

