#include "Engine.h"
#include "System.h"
#include <iostream>

Engine::~Engine() {
}

bool compareSystem(System *i, System *j) {
    return i->priority < j->priority;
}

bool Engine::init() {
    if(SDL_Init(SDL_INIT_TIMER) != 0) return false;
    for(auto s : systemDecoder) {
        if(!s.second->init()) {
            //std::cout << "There was an error initializing " << s.second->name << std::endl;
        }
    }
    return true;
}

void Engine::cleanup() {
    for(int i = 0; i < nextEntity; i++) {
        deleteEntity(i);
    }
    for(auto sys : systemDecoder) {
        sys.second->cleanup();
    }
    SDL_Quit();
}

int Engine::createEntity() {
	return nextEntity++;
}

void Engine::deleteEntity(int EntityID) {
	for(auto &s : systems) {
		s->removeEntity(EntityID);
	}
}

bool Engine::registerSystem(System *s) {
	std::pair<std::map<std::string, System*>::iterator, bool> result;
	result = systemDecoder.insert(std::make_pair(s->name, s));
	if(!result.second) {
		return false;
	}
	systems.push_back(s);
	std::sort(systems.begin(), systems.end(), compareSystem);
	return true;
}

System* Engine::getSystem(std::string name) {
	return systemDecoder[name];
}

void Engine::run() {
    running = true;
    unsigned int now, then = SDL_GetTicks();
    SDL_Delay(INITIAL_DELAY);
    while(running) {
        now = SDL_GetTicks();
        for(auto s : systems) s->update(now - then);
        then = now;
	}
}