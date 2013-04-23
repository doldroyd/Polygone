//Sound.h
//CS 397

#ifndef SOUND_H
#define SOUND_H

#include "SDL.h"
#include //sdl mixer
#include <map>

class SoundSystem : public System
{
  SoundSystem(engine* e): System( e ){ System::priority = SOUND_PRIORITY; music = NULL; sound1 = NULL;/*all the sounds are null*/ }
  Mix_Music* music;
  Mix_Chunk* sound1;
  Mox_Chunk* sound2;
  Mox_Chunk* sound3;
  Mox_Chunk* sound4;
  Mox_Chunk* sound5;
  Mox_Chunk* sound6;
  Mox_Chunk* sound7;
  Mox_Chunk* sound8;
  Mox_Chunk* sound9;
  Mox_Chunk* soundn;
	  	  
  bool init();
  void update(std::chrono::duration time);
  void cleanup();
  Component* addEntity(int EntityID);
  Component* getEntity(int EntityID);
  map<int, SoundComponent*> entities;

  bool removeEntity(int EntityID);
};

class SoundComponent : public Component
{
  string soundname;
  int channel;
};

#endif //SOUND_H
