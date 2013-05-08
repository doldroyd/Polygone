#include "Render.h"
#include "Physics.h"
#include "Position.h"
#include "Engine.h"

RenderSystem::RenderSystem(): System(RENDER_PRIORITY, RENDER_NAME){}
RenderSystem::~RenderSystem(void) {}

bool RenderSystem::init(void) {
	//Start SDL 
	SDL_Init( SDL_INIT_EVERYTHING );
	
	//The surfaces - add entities as needed
	SDL_Surface *foreground = NULL;
	 //SDL_Surface *background = NULL;
	SDL_Surface *screen = NULL;

	//Load images - one for each entity depending on entity id
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

	return true;
}

void RenderSystem::update(unsigned int delay) {
	for(auto p : render)
	{
		p.second.positionCom->x = p.second.positionCom->x + p.second.xv*delay;
		p.second.positionCom->y = p.second.positionCom->y + p.second.yv*delay;
	}

void RenderSystem::load() {
	//Load the images-one of these for each entity
	 //playerentity = load_image( ".png" );
	 //playerdeath = load_image(".png");
	 //courseentity = load_image( ".png" );
	background = load_image( "background.bmp" );

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

void RenderSystem::run() {
	RenderComponent *r;
	if(!r.Init()) {
		return -1;
	}
	r.load;

	//The offsets of the background 
	int bgX = 0, bgY = 0;

	//Scroll background 
	bgX -= 2; 

	//If the background has gone too far 
	if( bgX <= -background->w ) { 
		//Reset the offset 
		bgX = 0; 
	}
	
	//Apply images to surface (screen)
		void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) { 
			//Make a temporary rectangle to hold the offsets 
			SDL_Rect offset; 
			//Give the offsets to the rectangle 
			offset.x = x; 
			offset.y = y;

			//Blit the surface-one of these for each entity
			SDL_BlitSurface( source, NULL, destination, &offset );
		}

	//Apply the background to the screen 
	apply_surface( bgX, bgY, background, screen ); 
	apply_surface( bgX + background->w, bgY, background, screen );

	//Apply entities to screen-one of these for each entity
	  //apply_surface( entityposition.x, entityposition.y, blankentity, screen );

	//Update the screen 
	if( SDL_Flip( screen ) == -1 ) { 
		return 1; 
	}
}

void cleanup(){}

