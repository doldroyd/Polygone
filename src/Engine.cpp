#include "Engine.h"

int Engine::createEntity() {
	return nextEntity++;
}

void Engine::deleteEntity(int EntityID) {
	for(auto &s : systems) {
		s.removeEntity(EntityID);
	}
}

bool Engine::registerSystem(System &s, std::string name) {
	std::pair<std::map<std::string, System>::iterator, bool> result;
	result = systemDecoder.insert(std::make_pair(name, s));
	if(!result.second) {
		return false;
	}
	systems.push_back(s);
	std::sort(systems.begin(), systems.end());
	return true;
}

System* Engine::getSystem(std::string name) {
	return &(systemDecoder[name]);
}

void Engine::run() {
    unsigned int now, then = SDL_GetTicks();
    SDL_Delay(INITIAL_DELAY);
	for(auto &s : systems) {
        now = SDL_GetTicks();
		s.update(now - then);
        then = now;
	}
}