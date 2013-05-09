#include "Collision.h"
#include "Sound.h"

void CollisionSystem::consume(int Entity1, int Entity2) {
    PlayerStatusComponent* pc = (PlayerStatusComponent*) Engine::instance().getSystem(PLAYERSTATUS_NAME)->getEntity(Entity1);
    OrbComponent* o = (OrbComponent*) Engine::instance().getSystem(ORB_NAME)->getEntity(Entity2);
    pc->size += o->size;
}

void CollisionSystem::moveback(int EntityID) {
    //revert the movement of EntityID this turn
    PositionComponent* p = collision[EntityID].position;
    p->x = p->oldx;
    p->y = p->oldy;
}

bool CollisionSystem::checkCollision(int E1, int E2) {
    //returns true if they are colliding
    if( (collision[E1].position->y < collision[E2].position->y + collision[E2].height) &&
        (collision[E2].position->y < collision[E1].position->y + collision[E1].height) &&
        (collision[E1].position->x < collision[E2].position->x + collision[E2].width) &&
        (collision[E2].position->x < collision[E1].position->x + collision[E1].width) ) {
            return true;
    }
    return false;
}

CollisionSystem::CollisionSystem(): System(COLLISION_PRIORITY, COLLISION_NAME) {}
CollisionSystem::~CollisionSystem(){}

bool CollisionSystem::init() {
    return true;
}
void CollisionSystem::update(unsigned int delay){
    std::map<Collisions, std::vector<int>> c;
	SoundComponent* effect;
	int soundID;
	SoundSystem* soundsystem = (SoundSystem*) Engine::instance().getSystem(SOUND_NAME);
	soundID = Engine::instance().createEntity();
	effect = soundsystem->getEntity(soundID);
	effect->soundname = "sound1";

    for(auto &comp : collision) {
        c[comp.second.type].push_back(comp.first);
    }
    int p = c[player][0];
    //step 0: are we at a goal?
    for(auto &g : c[goal]) {
        if(checkCollision(p, g)) {
            //yay! need to stop the engine, remove all entities and do something else
            std::cout << "You win!" << std::endl;
        }
    }
    //Step 1: check player<>edge collisions until there is no collision between player<>wall and player<>edge
    bool edgehit = false;
    //first the edge(s)
    for(auto &e : c[edge]) {
        if(checkCollision(p, e)) {
            //move the player onto the screen;
            collision[p].position->x = collision[e].position->x + collision[e].width;
            edgehit = true;
        }
    }
    //now the walls, doesn't cause a recheck fault
    for(auto &w : c[wall]) {
        if(checkCollision(p, w)) {
            if(edgehit) {
                //hurt the player until ok
                bool done = false;
                PlayerStatusComponent *pc = (PlayerStatusComponent*) Engine::instance().getSystem(PLAYERSTATUS_NAME)->getEntity(p);
                while(!done) {
                    done = true;
                    pc->size -= 1;
                    collision[p].height -= 1;
                    collision[p].width -= 1;
                    collision[p].position->x -=0.5;
                    collision[p].position->y -=0.5;
                    if(checkCollision(p,w)) done = false;
                }
            }
            else {
                moveback(p);
                break;//no point in checking others, we must be valid now
            }
        }
    }
    //lastly check for orb hits, save the ones to remove
    std::vector<int> remove;
    for(auto &o : c[orb]) {
        if(checkCollision(p, o)) {
            consume(p, o);
            remove.push_back(o);
        }
    }
    //now remove them
    for(auto &e : remove) {
        Engine::instance().deleteEntity(e);
    }
}


void CollisionSystem::cleanup(){}


CollisionComponent* CollisionSystem::getEntity(int EntityID){
    auto i = collision.find(EntityID);
	if(i == collision.end()){
		collision[EntityID].position = (PositionComponent*) Engine::instance().getSystem(POSITION_NAME)->getEntity(EntityID);
	}
	return &(collision[EntityID]);
}

void CollisionSystem::loadEntity(int EntityID, const YAML::Node &node) {
    CollisionComponent *c = getEntity(EntityID);
    node["width"] >> c->width;
    node["height"] >> c->height;
    std::string temp;
    node["type"] >> temp;
    if(temp == "wall") c->type = wall;
    else if(temp == "orb") c->type = orb;
    else if(temp == "player") c->type = player;
    else if(temp == "edge") c->type = edge;
    else if(temp == "goal") c->type = goal;
}

bool CollisionSystem::removeEntity(int EntityID){
	return collision.erase(EntityID) == 1;
} 