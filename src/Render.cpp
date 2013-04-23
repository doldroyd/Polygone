#include "Render.h"
//#include "Position.h"

Render::~Render(void) {
}

bool Render::Init(void) {
	//Start SDL 
	SDL_Init( SDL_INIT_EVERYTHING );
	
	//The surfaces - add entities as needed
	SDL_Surface *blankentity = NULL;
	SDL_Surface *background = NULL;
	SDL_Surface *screen = NULL;

	//playerentity
	//backgroundentity
	//wallentity
	//courseentity
	//orbentity

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

	running = true;
	return true;
}

void Render::Load() {
	//Load the images-one of these for each entity
	blankentity = load_image( ".png" ); 
	background = load_image( "background.png" );
	
	//Apply the background to the screen 
	apply_surface( 0, 0, background, screen );

}

void Render::Run() {
	Render r;
	if(!r.Init()) {
		return -1;
	}
	r.Load;

	while(running) {

		//Apply entities to screen-one of these for each entity
		apply_surface( entityposition.x, entityposition.y, blankentity, screen );

		//Update the screen 
		if( SDL_Flip( screen ) == -1 ) { 
			return 1; 
		}
		
	}
}