#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <vector>
#include <algorithm>
#include <SDL.h>

#include "System.h"

#define INITIAL_DELAY 5

class Engine{
	public:
		Engine();
		~Engine();

		int createEntity();
		void deleteEntity(int EntityID);
		bool registerSystem(System &s, std::string name);
		System* getSystem(std::string name);
	
		void run();

	private:
		std::map<std::string, System> systemDecoder;
		std::vector<System> systems;

		bool running;
		int nextEntity;
};

#endif //ENGINE_H
