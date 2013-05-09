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
#include <iostream>

int main(int argc, char* argv[]) {
    //Create, register, and initialize Systems
    Engine::instance().registerSystem(new GroupSystem);
    Engine::instance().registerSystem(new PositionSystem);
    Engine::instance().registerSystem(new PhysicsSystem);
    Engine::instance().registerSystem(new SoundSystem);
    Engine::instance().registerSystem(new RenderSystem);
    Engine::instance().registerSystem(new InputSystem);
    Engine::instance().registerSystem(new CollisionSystem);
    Engine::instance().init();
    //start engine
    Loader::load("res/test.yaml");
    Engine::instance().run();
    //load level
    //cleanup
    Engine::instance().cleanup();
	return 0;
}