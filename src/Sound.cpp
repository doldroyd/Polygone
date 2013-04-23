//Sound.cpp
//implementation for the sound system
//CS 397

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





