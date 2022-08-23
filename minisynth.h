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
	void		*mlx;
	void		*mlx_win;
	t_buffer	*img_buffer;
	int 	size_x;
	int		size_y;
} t_data;
#endif //MINISYNTH_MINISYNTH_H