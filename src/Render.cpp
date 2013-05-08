#include "Render.h"
#include "Physics.h"
#include "Position.h"
#include "Engine.h"

RenderSystem::RenderSystem(): System(RENDER_PRIORITY, RENDER_NAME){}
RenderSystem::~RenderSystem(void) {}

bool compareLayer(System *i, System *j) {
    return i->priority < j->priority;
}

bool RenderSystem::registerLayer(System &s) {
	std::pair<std::map<std::string, System*>::iterator, bool> result;
	result = render.insert(std::make_pair(s.name, &s));
	if(!result.second) {
		return false;
	}
	layers.push_back(&s);
	std::sort(layers.begin(), layers.end(), compareLayer);
	return true;
}

bool RenderSystem::init(void) {
	//Start SDL 
	SDL_Init( SDL_INIT_EVERYTHING );
	//Set up screen 
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

	//Load image function
	SDL_Surface *load_image( std::string filename ) { 
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

	//Load the images-one of these for each entity
	 playerentity = load_image( "player.png" );
	 //playerdeath = load_image("playerKO.png");
	 //courseentity = load_image( ".png" );
	 background = load_image( "background.png" );

	//The offsets of the background 
	int bgX = 0, bgY = 0;

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

	return true;
}

void RenderSystem::update(unsigned int delay) {
	//Scroll background 
	bgX -= 2; 

	//If the background has gone too far 
	if( bgX <= -background->w ) { 
		//Reset the offset 
		bgX = 0;

	//Apply the background to the screen 
	apply_surface( bgX, bgY, background, screen );
	apply_surface( bgX + background->w, bgY, background, screen );

	for(auto p : render)
	{
		apply_surface( p.second.positionCom->x, p.second.positionCom->y, playerentity, surface );
		//p.second.positionCom->x
		//p.second.positionCom->y
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


bool RenderSystem::removeEntity(int EntityID){
	bool retval;
	retval=((1==render.erase(EntityID))?true:false);
	return retval;
}

void cleanup(){}

