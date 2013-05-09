//Sound.h
//CS 397

#ifndef SOUND_H
#define SOUND_H

#include "SDL.h"
#include "SDL_mixer.h"
#include <map>
#include <string>

#include "System.h"

#define SOUND_PRIORITY 6 //placeholder
#define SOUND_NAME "Sound" //Placeholder

class SoundComponent : public Component
{
  public:
    std::string soundname;
    int channel;
};

class SoundSystem : public System
{
public:
	SoundSystem(): System(SOUND_PRIORITY, SOUND_NAME) {  music = NULL; sound1 = NULL; /*sound2 = NULL;*/ sound3 = NULL;}
private:
  Mix_Music* music;
  Mix_Chunk* sound1;
 // Mix_Chunk* sound2;
  Mix_Chunk* sound3;

  std::map<int, SoundComponent> entities;
	  	  
public:
  virtual bool init();
  virtual void update(unsigned int delay);
  virtual void cleanup();
  virtual SoundComponent* getEntity(int EntityID);
  virtual void loadEntity(int EntityID, const YAML::Node &node);

  virtual bool removeEntity(int EntityID);
};

#endif //SOUND_H
