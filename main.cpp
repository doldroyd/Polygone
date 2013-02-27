#include "SDL.h"
#include "Engine.h"

int main(int argc, char* argv[]) {
	Engine e;
	if(!e.Init()) {
		return -1;
	}
	e.Run();
	e.Cleanup();
	return 0;
}