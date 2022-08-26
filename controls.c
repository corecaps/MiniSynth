//
// Created by corecaps on 26/08/22.
//

#include "minisynth.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		win_close(data);
	return (0);
}