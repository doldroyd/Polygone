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
			case SDLK_UP: position.x += 5; break; //Need correct position component
			case SDLK_DOWN: position.x -= 5; break; //Need correct position component
			case SDLK_LEFT: position.y -= 5; break; //Need correct position component
			case SDLK_RIGHT: position.y += 5; break; //Need correct position component
			default : ;
		}
	}
}

Input::Mouse(void){
	//While the mouse is moving, constantly get its position
	while(event.type == SDL_MOUSEMOTION)
	{
		x = event.motion.x;
		y = event.motion.y;
	}

	//While a mouse button is pressed
	while(event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x; //Need position component?
            y = event.button.y; //Need position component?
        }
    }
	    //If a mouse button was released
    if( event.type == SDL_MOUSEBUTTONUP )
    {
        //If the left mouse button was released
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x; //Need position component?
            y = event.button.y; //Need position component?

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
            }
        }
    }
}