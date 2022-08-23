//
// Created by corecaps on 24/08/22.
//

#include "minisynth.h"

int audio_callback( const void *inputBuffer, void *outputBuffer,
						   unsigned long framesPerBuffer,
						   const PaStreamCallbackTimeInfo* timeInfo,
						   PaStreamCallbackFlags statusFlags,
						   void *user_data )
{
	t_data			*data = (t_data *)user_data;
	float			*out = (float*)outputBuffer;
	unsigned long	i;
	(void) inputBuffer;

	for( i=0; i < framesPerBuffer; i++ )
	{
		*out++ = 0.0;  /* left */
		*out++ = 0.0;  /* right */
	}
	return 0;
}