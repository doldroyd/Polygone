//Sound.cpp
//implementation for the sound system
//CS 397

#include "Sound.h"
#include <iostream>

using namespace std;

bool SoundSystem::init()
{
  SDL_InitSubSystem(SDL_INIT_AUDIO);
  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
  {
	cout << "failed in init" << endl;
    return false;    
  }

  music = Mix_LoadMUS( "res/music.wav" );
  sound1 = Mix_LoadWAV( "res/sound1.wav" );
//  sound2 = Mix_LoadWAV( "res/sound2.wav" );
  sound3 = Mix_LoadWAV( "res/sound3.wav" );

  
  if( music == NULL || sound1 == NULL /*|| sound2 == NULL */|| sound3 == NULL)
  {
	  cout << "fails in sound files" << endl;
	  return false;
  }
  Mix_PlayMusic( music, -1 );
  return true;
}

void SoundSystem::cleanup()
{
  Mix_FreeChunk( sound1 );
//  Mix_FreeChunk( sound2 );
  Mix_FreeChunk( sound3 );
  Mix_FreeMusic( music );
  Mix_CloseAudio();
  SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

SoundComponent* SoundSystem::getEntity(int EntityID)
{
  return &(entities[EntityID]);
}


bool SoundSystem::removeEntity( int EntityID)
{
  return( entities.erase( EntityID ) > 0 );
}

void SoundSystem::update(unsigned int delay)
{

	if( Mix_PlayingMusic == 0 )
	{
		if( Mix_PlayMusic( music, -1 ) == -1 )
		    return;
	}


  while( entities.size() > 0 )
  {
	SoundComponent tempComponent = entities.begin()->second; 
	if( tempComponent.soundname == "musicon" )
	{
	  //do music on things
		if( Mix_PlayingMusic == 0 )
		{
		  if( Mix_PlayMusic( music, -1 ) == -1 )
		    return;
		}
	}

	
	if( tempComponent.soundname == "musicpause" )
	{	 
		//do music pause things
		if( Mix_PlayingMusic == 0 )
		{
		  if( Mix_PlayMusic( music, -1 ) == -1 )
			  return;
		}
		else
        {
            //If the music is paused
            if( Mix_PausedMusic() == 1 )
            {
                //Resume the music
                Mix_ResumeMusic();
            }
            //If the music is playing
            else
            {
                //Pause the music
                Mix_PauseMusic();
            }
        }
	}
	else if( tempComponent.soundname == "musicoff" )
	{
      //do music off things
      Mix_HaltMusic();
	}
    if( tempComponent.soundname == "sound1" )
    {
	   if( Mix_PlayChannel( tempComponent.channel, sound1, 0 )  == -1 )
					    return;
		              break;
    }
    if( tempComponent.soundname == "sound2" )
    {
	   if( Mix_PlayChannel( tempComponent.channel, sound1, 0 )  == -1 )
					    return;
		              break;
    }
    if( tempComponent.soundname == "sound3" )
    {
	   if( Mix_PlayChannel( tempComponent.channel, sound1, 0 )  == -1 )
					    return;
		              break;
    }
  
    
	entities.erase( entities.begin() );
  //get rid of this component / / get next component
  }
}	              

void SoundSystem::loadEntity(int EntityID, const YAML::Node &node) {
    SoundComponent *s = getEntity(EntityID);
    //need to fill in here
}