#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <vector>

#include "System.h"

class Engine{
	public:
		Engine();
		~Engine();

		int createEntity();
		void deleteEntity(int EntityID);
		bool registerSystem(System &s);
		System* getSystem(std::string name);
	
		void run();

	private:
		std::map<std::string, System> systemDecoder;
		std::vector<System> systems;

		bool running;
		int nextEntity;
};

#endif //ENGINE_H
