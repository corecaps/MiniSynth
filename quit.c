//
// Created by corecaps on 26/08/22.
//
#include "minisynth.h"

int	win_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}