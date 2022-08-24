//
// Created by corecaps on 24/08/22.
//
#include "minisynth.h"

int render(t_data *data)
{
	mlx_put_image_to_window(data->mlx,data->mlx_win,data->ui_background,0,0);
	return (0);
}