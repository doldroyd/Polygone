//Sound.cpp
//implementation for the sound system
//CS 397

#include "Sound.h"

bool SoundSystem::init()
{
  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
  {
    return false;    
  }

  music = Mix_LoadMUS( "music.wav" );
  sound1 = Mix_LoadWAV( "sound1.wav" );
  sound2 = Mix_LoadWAV( "sound2.wav" );
  sound3 = Mix_LoadWAV( "sound3.wav" );

  
  if( music == NULL || sound1 == NULL /* || all the sounds )*/)
  {
    return false;
  }
  return true;
}

void SoundSystem::cleanup()
{
  Mix_FreeChunk( sound1 );
  Mix_FreeChunk( sound2 );
  Mix_FreeChunk( sound3 );
  Mix_FreeMusic( music );
  Mix_CloseAudio();
}

SoundComponent* SoundSystem::getEntity(int EntityID)
{
  return &(entities[EntityID]);
}


bool SoundSystem::removeEntity( int EntityID)
{
  return( entities.erase( EntityID ) > 0 ? true : false );
}

void SoundSystem::update(unsigned int delay)
{
  while( entities.size() > 0 )
  {
    if( Mix_PlayingMusic == 0 )
		{
		  if( Mix_PlayMusic( music, -1 ) == -1 )
		    return;
		}
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