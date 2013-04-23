#include "SDL.h"
#include "Engine.h"

int main(int argc, char* argv[]) {
    //Create and initialize Engine
    Engine e = Engine();
    e.init();
    //Create, register, and initialize Systems

    //start engine
    e.run();
    //cleanup
    e.cleanup();
	return 0;
}