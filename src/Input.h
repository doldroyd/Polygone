#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include "System.h"

#include "Position.h"

class Input{
	public:
		Input();
		~Input();

		Key();
		Mouse();

		int mx, my;
};
#endif