#include "Engine.h"

Engine::Engine() {
}

Engine::~Engine() {
}

bool compareSystem(System *i, System *j) {
    return i->priority < j->priority;
}

bool Engine::init() {
    return SDL_Init(0) == 0;
}

void Engine::cleanup() {
    for(auto &system : systemDecoder) {
        system.second->cleanup();
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

bool Engine::registerSystem(System &s, std::string name) {
	std::pair<std::map<std::string, System*>::iterator, bool> result;
	result = systemDecoder.insert(std::make_pair(name, &s));
	if(!result.second) {
		return false;
	}
	systems.push_back(&s);
	std::sort(systems.begin(), systems.end(), compareSystem);
	return true;
}

System* Engine::getSystem(std::string name) {
	return systemDecoder[name];
}

void Engine::run() {
    unsigned int now, then = SDL_GetTicks();
    SDL_Delay(INITIAL_DELAY);
    while(running) {
        now = SDL_GetTicks();
        for(auto &s : systems) s->update(now - then);
        then = now;
	}
}