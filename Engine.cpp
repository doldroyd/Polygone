#include "Engine.h"


Engine::Engine(void) {
	//TODO: read settings from file
	windowWidth = 640;
	windowHeight = 320;
	windowBPP = 32;
}


Engine::~Engine(void) {
}

bool Engine::Init(void) {
	if(SDL_Init(SDL_INIT_EVERYTHING) < -1) {
		return false;
	}
	screen = SDL_SetVideoMode(windowWidth, windowHeight, windowBPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen == NULL) {
		return false;
	}
	running = true;
	return true;
}

void Engine::Run() {
	while(running) {
		Events();
		Loop();
		Render();
	}
}

void Engine::Events() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			running = false;
		}
	}
}

void Engine::Render() {
}

void Engine::Loop() {
}

void Engine::Cleanup() {
	SDL_FreeSurface(screen);
	SDL_Quit();
}