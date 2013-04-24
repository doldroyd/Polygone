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
    SoundSystem(): System(SOUND_PRIORITY, SOUND_NAME) {  music = NULL; sound1 = NULL; sound2 = NULL; sound3 = NULL;
                                        sound4 = NULL; sound5 = NULL; sound6 = NULL; sound7 = NULL; sound8 = NULL; sound9 = NULL; soundn = NULL;/*all the sounds are null*/ }
  Mix_Music* music;
  Mix_Chunk* sound1;
  Mix_Chunk* sound2;
  Mix_Chunk* sound3;
  Mix_Chunk* sound4;
  Mix_Chunk* sound5;
  Mix_Chunk* sound6;
  Mix_Chunk* sound7;
  Mix_Chunk* sound8;
  Mix_Chunk* sound9;
  Mix_Chunk* soundn;
	  	  
  bool init();
  void update(unsigned int delay);
  void cleanup();
  Component* getEntity(int EntityID);
  std::map<int, SoundComponent> entities;

  bool removeEntity(int EntityID);
};

#endif //SOUND_H
