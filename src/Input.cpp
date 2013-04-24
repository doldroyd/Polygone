#include "Input.h"

Input::Input(void){

}

Input::Input(~void){
}

Input::Key(void){
	//While a key is pressed
	while(event.type == SDL_KEYDOWN){
		switch( event.key.keysym.sym )
		{
			//For each key, an action respectively
			case SDLK_UP: position.y += 5; break; 
			case SDLK_DOWN: position.y -= 5; break;
			case SDLK_LEFT: position.x -= 5; break;
			case SDLK_RIGHT: position.x += 5; break;
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