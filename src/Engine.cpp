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
        s.second->init();
    }
    return true;
}

void Engine::cleanup() {
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
        std::cout << now-then << std::endl;
        for(auto s : systems) {
            std::cout << s->name << " ";
            s->update(now - then);
        }
        std::cout << std::endl;
        then = now;
	}
}