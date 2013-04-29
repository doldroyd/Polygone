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
  sound4 = Mix_LoadWAV( "sound4.wav" );
  sound5 = Mix_LoadWAV( "sound5.wav" );
  sound6 = Mix_LoadWAV( "sound6.wav" );
  sound7 = Mix_LoadWAV( "sound7.wav" );
  sound8 = Mix_LoadWAV( "sound8.wav" );
  sound9 = Mix_LoadWAV( "sound9.wav" );
  soundn = Mix_LoadWAV( "soundn.wav" );
  
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
  Mix_FreeChunk( sound4 );
  Mix_FreeChunk( sound5 );
  Mix_FreeChunk( sound6 );
  Mix_FreeChunk( sound7 );
  Mix_FreeChunk( sound8 );
  Mix_FreeChunk( sound9 );
  Mix_FreeChunk( soundn );
  Mix_FreeMusic( music );
  Mix_CloseAudio();
}

Component* SoundSystem::getEntity(int EntityID)
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
    /* switch cannot use a string, removed for now
	switch( tempComponent.soundname )
	{
	  case "sound1" : if( Mix_PlayChannel( tempComponent.channel, sound1, 0 ) ) == -1 )
					    return;
		              break;
      case "sound2" : if( Mix_PlayChannel( tempComponent.channel, sound2, 0 ) ) == -1 )
					    return;
		              break;
	  case "sound3" : if( Mix_PlayChannel( tempComponent.channel, sound3, 0 ) ) == -1 )
					    return;
		              break;
	  case "sound4" : if( Mix_PlayChannel( tempComponent.channel, sound4, 0 ) ) == -1 )
					    return;
		              break;
	  case "sound5" : if( Mix_PlayChannel( tempComponent.channel, sound5, 0 ) ) == -1 )
					    return;
					  break;
	  case "sound6" : if( Mix_PlayChannel( tempComponent.channel, sound6, 0 ) ) == -1 )
					    return;
		              break;
	  case "sound7" : if( Mix_PlayChannel( tempComponent.channel, sound7, 0 ) ) == -1 )
					    return;
		              break;
      case "sound8" : if( Mix_PlayChannel( tempComponent.channel, sound8, 0 ) ) == -1 )
					    return;
		              break;
	  case "sound9" : if( Mix_PlayChannel( tempComponent.channel, sound9, 0 ) ) == -1 )
					    return;
		              break;
	  case "soundn" : if( Mix_PlayChannel( tempComponent.channel, soundn, 0 ) ) == -1 )
					    return;
	}
    */
	entities.erase( entities.begin() );
  //get rid of this component / / get next component
  }
}	              