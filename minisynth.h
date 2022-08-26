/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisynth.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:40:06 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/23 23:40:39 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISYNTH_MINISYNTH_H
#define MINISYNTH_MINISYNTH_H
# include "inc/portaudio.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "config.h"
typedef struct s_stereo_phase
{
	double	right;
	double	left;
} t_stereo_phase;
typedef struct s_buffer
{
	void	*img;
	char	*address;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_buffer;
typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	t_buffer		*img_buffer;
	void			*ui_background;
	int 			size_x;
	int				size_y;
	PaStream		*audio_stream;
	t_stereo_phase	main_phase;
	double			main_gain;
} t_data;
int		audio_init(t_data *data);
int		audio_callback( const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,const PaStreamCallbackTimeInfo* timeInfo,PaStreamCallbackFlags statusFlags,void *user_data );
void	graphic_init(t_data *data);
void	print_device_list(const PaDeviceInfo *info, const PaHostApiInfo *host_api);
int		render(t_data *data);
int		key_pressed(int keycode, t_data *data);
int		win_close(t_data *data);
#endif //MINISYNTH_MINISYNTH_H