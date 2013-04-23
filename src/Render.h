#ifndef RENDER_H
#define RENDER_H

#include <map>
#include <vector>

#include "System.h"
#include "SDL.h"

class Render{
	public:
		Render();
		~Render();

		//bool registerSystem(System &s);
		//System* getSystem(std::string name);
	
		void run();

	private:
		std::map<std::string, System> systemDecoder;
		std::vector<System> systems;

		bool running;
		int nextEntity;
};

#endif //RENDER_H