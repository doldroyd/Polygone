#include "SDL.h"
#include "Engine.h"

int main(int argc, char* argv[]) {
    Engine::instance().init();
    //Create, register, and initialize Systems

    //start engine
    Engine::instance().run();
    //cleanup
    Engine::instance().cleanup();
	return 0;
}