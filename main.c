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

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_data *data;

	data = alloc_mem();
	audio_init(data);
	graphic_init(data);
	graphic_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}