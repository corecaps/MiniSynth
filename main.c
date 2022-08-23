/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:32:35 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/23 23:32:36 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisynth.h"

enum {ARG_NAME,ARG_NARGS};

int main(int argc,char **argv)
{
	(void) argc;
	(void) argv;
	t_data	*data = NULL;

	data = malloc(sizeof (t_data *));
	if (data == NULL)
	{
		printf("Not enough memory\n");
		return (-1);
	}
	data->img_buffer = malloc(sizeof (t_buffer *));
	if (data->img_buffer == NULL)
	{
		free(data);
		printf("Not enough memory\n");
		exit (-1);
	}
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
	return (0);
}