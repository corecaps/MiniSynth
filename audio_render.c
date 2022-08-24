/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:23:40 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/24 01:23:53 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void) timeInfo;
	(void) statusFlags;

	for( i=0; i < framesPerBuffer; i++ )
	{
		*out++ = (float)(data->main_phase.left * data->main_gain);  /* left */
		*out++ = (float)(data->main_phase.right * data->main_gain);  /* right */
	}
	return paContinue;
}