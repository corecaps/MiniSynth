/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:12:20 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/26 11:12:26 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisynth.h"

t_data *alloc_mem()
{
	t_data	*data = NULL;

	data = malloc(sizeof (t_data));
	if (data == NULL)
	{
		printf("Not enough memory\n");
		exit(-1);
	}
	data->img_buffer = malloc(sizeof (t_buffer));
	if (data->img_buffer == NULL)
	{
		free(data);
		printf("Not enough memory\n");
		exit(-1);
	}
	return (data);
}

void graphic_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->mlx_win, 17, 0, win_close, data);
	mlx_loop_hook(data->mlx, render, data);
}

void graphic_init(t_data *data)
{
	int width;
	int height;

	data->size_x = SIZEX;
	data->size_y = SIZEY;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		printf("mlx initialisation error\n");
		exit (-2);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->size_x + 1,
								   data->size_y + 1,
								   "fractol");
	data->img_buffer->img = mlx_new_image(data->mlx,
										  data->size_x + 1,
										  data->size_y + 1);
	data->img_buffer->address = mlx_get_data_addr(data->img_buffer->img,
												  &data->img_buffer->bit_per_pixel,
												  &data->img_buffer->line_length,
												  &data->img_buffer->endian);
	data->ui_background = mlx_xpm_file_to_image(data->mlx,UI_BACKGROUND,&width,&height);
}

int	audio_init(t_data *data)
{
	const PaDeviceInfo	*info = NULL;
	const PaHostApiInfo	*host_api= NULL;
	PaStreamParameters	out_param,in_param;
	int					id;
	Pa_Initialize();
	print_device_list(info, host_api);
	printf("\n------\nType AUDIO output device number:\n");
	scanf("%d",&id);
	info = Pa_GetDeviceInfo(id);
	host_api = Pa_GetHostApiInfo(info->hostApi);
	set_audio_param(data, info, id, &out_param, &in_param);
	Pa_OpenStream(data->audio_stream,
				  &in_param,
				  &out_param,
				  SAMPLING_RATE,
				  FRAME_BLOCK,
				  paClipOff,
				  audio_callback,
				  data);
	Pa_StartStream(data->audio_stream);
	return (0);
}

void set_audio_param(t_data *data, const PaDeviceInfo *info, int id,
					 PaStreamParameters *out_param,
					 PaStreamParameters *in_param)
{
	(*out_param).device = id;
	(*out_param).channelCount = 2;
	(*out_param).sampleFormat = paFloat32;
	(*out_param).suggestedLatency = info->defaultLowOutputLatency;
	(*out_param).hostApiSpecificStreamInfo = NULL;
	(*in_param).device = id;
	(*in_param).channelCount = 0;
	(*in_param).sampleFormat = paFloat32;
	(*in_param).suggestedLatency = info->defaultLowInputLatency;
	(*in_param).hostApiSpecificStreamInfo = NULL;
	data->main_phase.left = 0.0;
	data->main_phase.right = 0.0;
	data->main_gain = 0.0;
}

void print_device_list(const PaDeviceInfo *info, const PaHostApiInfo *host_api)
{
	int i;
	for (i = 0; i < Pa_GetDeviceCount(); i++)
	{
		info = Pa_GetDeviceInfo(i);
		host_api = Pa_GetHostApiInfo(info->hostApi);
		if (info->maxOutputChannels > 0)
			printf("%d:\t[%s]\t%s (output)\n",i,host_api->name,info->name);
	}
}
