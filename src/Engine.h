#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"

class Engine {
private:
	int windowWidth;
	int windowHeight;
	int windowBPP;

	SDL_Surface* screen;

	bool running;

	void Events();
	void Loop();
	void Render();

public:
	Engine(void);
	~Engine(void);

	bool Init();
	void Run();
	void Cleanup();

};

#endif // ENGINE_H