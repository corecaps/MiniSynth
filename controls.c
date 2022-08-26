/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:11:55 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/26 11:12:06 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisynth.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		win_close(data);
	return (0);
}
