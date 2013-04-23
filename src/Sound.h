//Sound.h
//CS 397

#ifndef SOUND_H
#define SOUND_H

#include "SDL.h"
#include "SDL_mixer.h"
#include <map>

class SoundSystem : public System
{
  SoundSystem(engine* e): System( e ){ System::priority = SOUND_PRIORITY; music = NULL; sound1 = NULL; sound2 = NULL; sound3 = NULL;
                                        sound4 = NULL; sound5 = NULL; sound6 = NULL; sound7 = NULL; sound8 = NULL; sound9 = NULL; soundn = NULL;/*all the sounds are null*/ }
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
  Component* getEntity(int EntityID);
  map<int, SoundComponent> entities;

  bool removeEntity(int EntityID);
};

class SoundComponent : public Component
{
  string soundname;
  int channel;
};

#endif //SOUND_H
