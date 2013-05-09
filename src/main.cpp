#include "SDL.h"
#include "Engine.h"
#include "Group.h"
#include "Position.h"
#include "Physics.h"
#include "Sound.h"
#include "Render.h"
#include "Input.h"
#include "Loader.h"
#include "Collision.h"

int main(int argc, char* argv[]) {
    //Create, register, and initialize Systems
    Engine::instance().registerSystem(GroupSystem());
    Engine::instance().registerSystem(PositionSystem());
    Engine::instance().registerSystem(PhysicsSystem());
    Engine::instance().registerSystem(SoundSystem());
    Engine::instance().registerSystem(RenderSystem());
    Engine::instance().registerSystem(InputSystem());
    Engine::instance().registerSystem(CollisionSystem());
    Engine::instance().init();
    //start engine
    Loader::load("test.yaml");
    Engine::instance().run();
    //load level
    //cleanup
    Engine::instance().cleanup();
	return 0;
}