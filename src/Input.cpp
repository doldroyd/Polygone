#include "Input.h"

InputSystem::InputSystem() : System(INPUT_PRIORITY, INPUT_NAME) {}
InputSystem::~InputSystem(){}

InputComponent* InputSystem::getEntity(int EntityID){

	//insert
    auto i = input.find(EntityID);
	if(i == input.end()){
		input[EntityID].physicsCom = (PhysicsComponent*) Engine::instance().getSystem(POSITION_NAME)->getEntity(EntityID);
	}
	InputComponent* retval = &(input[EntityID]);
	return retval;
}

bool InputSystem::removeEntity(int EntityID){
	bool retval;
	retval=((1==input.erase(EntityID))?true:false);
	return retval;
}

void InputSystem::update(unsigned int delay){
	
	SDL_Event event;
	SDL_PumpEvents();
	
	//While a key is pressed
	while(SDL_PeepEvents( &event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_KEYDOWN))){
		switch( event.key.keysym.sym )
		{
			//For each key, an action respectively
		case SDLK_UP: input.begin()->second.physicsCom->yv += 5 ; break; 
			case SDLK_DOWN:  input.begin()->second.physicsCom->yv -= 5 ; break;
			case SDLK_LEFT:  input.begin()->second.physicsCom->xv -= 5 ; break;
			case SDLK_RIGHT:  input.begin()->second.physicsCom->xv += 5 ; break;
			default : ;
		}
	}

	//While a key is released
	while(SDL_PeepEvents( &event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_KEYUP))){
		switch( event.key.keysym.sym )
		{
			//For each key, an action respectively
			case SDLK_UP:  input.end()->second.physicsCom->yv = 0  ; break; 
			case SDLK_DOWN: input.end()->second.physicsCom->yv = 0; break;
			case SDLK_LEFT: input.end()->second.physicsCom->xv = 0; break;
			case SDLK_RIGHT: input.end()->second.physicsCom->xv = 0; break;
			default : ;
		}
	}

	//While the mouse is moving, constantly get its position
	while(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_MOUSEMOTION))){
		//mx = event.motion.x;
		//my = event.motion.y;
		//If in game, set main character entity's coordinates as mouse coordinates
		//if (game == running){
		//	position.x = mx;
		//	position.y = my;
		//}
	}

	//While a mouse button is pressed
	while(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_MOUSEBUTTONDOWN))){
		//If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            mx = event.button.x;
            my = event.button.y;
        }
    }

	//If a mouse button was released
	while(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_MOUSEBUTTONUP))){
        //If the left mouse button was released
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            mx = event.button.x;
            my = event.button.y;

            //If the mouse is over the button
            //if( ( mx > box.x ) && ( mx < box.x + box.w ) && ( my > box.y ) && ( my < box.y + box.h ) )
            //{
            //}
        }
    }
}