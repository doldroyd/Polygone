#include "Input.h"
#include "Render.h"
#include <iostream>

InputSystem::InputSystem() : System(INPUT_PRIORITY, INPUT_NAME) {}
InputSystem::~InputSystem(){}

InputComponent* InputSystem::getEntity(int EntityID){

	//insert
    auto i = input.find(EntityID);
	if(i == input.end()){
		input[EntityID].physicsCom = (PhysicsComponent*) Engine::instance().getSystem(PHYSICS_NAME)->getEntity(EntityID);
		input[EntityID].positionCom = (PositionComponent*) Engine::instance().getSystem(POSITION_NAME)->getEntity(EntityID);
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
			case SDLK_UP: input.begin()->second.physicsCom->yv -= .3 ; break; 
			case SDLK_DOWN:  input.begin()->second.physicsCom->yv += .3 ; break;
			case SDLK_LEFT:  input.begin()->second.physicsCom->xv -= .2 ; break;
			case SDLK_RIGHT:  input.begin()->second.physicsCom->xv += .5 ; break;
			default : ;
		}
	}

	//While a key is released
	while(SDL_PeepEvents( &event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_KEYUP))){
		switch( event.key.keysym.sym )
		{
			//For each key, an action respectively
			case SDLK_UP:  input.begin()->second.physicsCom->yv += .3  ; break; 
			case SDLK_DOWN: input.begin()->second.physicsCom->yv -= .3; break;
			case SDLK_LEFT: input.begin()->second.physicsCom->xv += .2; break;
			case SDLK_RIGHT: input.begin()->second.physicsCom->xv -= .5; break;
			case SDLK_m: mouseenabled = !mouseenabled;
			default : ;
		}
	}

	if(mouseenabled == true){
		SDL_ShowCursor(SDL_DISABLE);
		//While the mouse is moving, constantly get its position
		while(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_MOUSEMOTION))){
			//if in game then set mouse offset as player entity
			//if( game == running){
				input.begin()->second.positionCom->x = event.motion.x + *cameraX;
				input.begin()->second.positionCom->y = event.motion.y;
			//}
		}

		//While a mouse button is pressed
		while(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_MOUSEBUTTONDOWN))){
			//If the left mouse button was pressed
			if( event.button.button == SDL_BUTTON_LEFT )
			{
				//If mouse offset is equal to the button offset, then do button down gif
				//If(mx == button.x && my == button.y){
				//	button down gif nonexistent at the moment
				//}
			}	
		}

		//If a mouse button was released
		while(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_EVENTMASK(SDL_MOUSEBUTTONUP))){
	        //If the left mouse button was released
			if( event.button.button == SDL_BUTTON_LEFT )
			{
	            //Get the mouse offsets
				//mx = event.button.x;
				//my = event.button.y;
	
	            //If the mouse is over the button
				//if( ( mx > box.x ) && ( mx < box.x + box.w ) && ( my > box.y ) && ( my < box.y + box.h ) )
				//{
				//}
			}
		}
	}
	else{SDL_ShowCursor(SDL_ENABLE);}
}

void InputSystem::cleanup() {}

void InputSystem::loadEntity(int EntityID, const YAML::Node &node) {
    InputComponent *i = getEntity(EntityID);
    //pass?
}

bool InputSystem::init() {
	mouseenabled = false;
	SDL_WM_GrabInput(SDL_GRAB_ON);
	cameraX = &(((RenderSystem*) Engine::instance().getSystem(RENDER_NAME))->cameraX);
    return true;
}