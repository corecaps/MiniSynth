/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:12:10 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/26 11:12:16 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisynth.h"

int render(t_data *data)
{
	mlx_put_image_to_window(data->mlx,data->mlx_win,data->ui_background,0,0);
	return (0);
}
