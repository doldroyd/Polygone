#include "Input.h"

InputSystem::InputSystem(): System(INPUT_PRIORITY, INPUT_NAME) {}
InputSystem::~InputSystem(){}


void InputSystem::update(unsigned int delay){

	SDL_PumpEvents();
	//probably still have this wrong v.v I'm a failure lol
	SDL_PeepEvents( events, 10, SDL_GETEVENT, mask);

	//While a key is pressed
	while(event.type == SDL_KEYDOWN){
		switch( event.key.keysym.sym )
		{
			//For each key, an action respectively
			case SDLK_UP: ; break; 
			case SDLK_DOWN: ; break;
			case SDLK_LEFT: ; break;
			case SDLK_RIGHT: ; break;
			default : ;
		}
	}
}

Input::Mouse(void){
	//While the mouse is moving, constantly get its position
	while(event.type == SDL_MOUSEMOTION)
	{
		mx = event.motion.mx;
		my = event.motion.my;
	}

	//While a mouse button is pressed
	while(event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            mx = event.button.mx;
            my = event.button.my;
        }
    }
	    //If a mouse button was released
    if( event.type == SDL_MOUSEBUTTONUP )
    {
        //If the left mouse button was released
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            mx = event.button.mx;
            my = event.button.my;

            //If the mouse is over the button
           // if( ( mx > box.x ) && ( mx < box.x + box.w ) && ( my > box.y ) && ( my < box.y + box.h ) )
            //{
            //}
        }
    }
}