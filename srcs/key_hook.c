/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:43:08 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 14:46:36 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	ft_key_hook(int keycode, t_datas_global *all_datas)
{
	if (keycode == ESC)
		ft_print_error(MESSAGE_END_EXIT, all_datas);
	if (keycode == W)
		player_3d_move(all_datas, 0);
	if (keycode == S)
		player_3d_move(all_datas, 1);
	if (keycode == LEFT_ARROW)
	{
		all_datas->player_datas->rot_speed = 0.2;
		player_3d_move(all_datas, 2);
	}
	if (keycode == RIGHT_ARROW)
	{
		all_datas->player_datas->rot_speed = -0.2;
		player_3d_move(all_datas, 2);
	}
	if (keycode == D)
		player_3d_move(all_datas, 3);
	if (keycode == A)
		player_3d_move(all_datas, 4);
	return (0);
}

/*
	dir
		-> 0  =  avance
		-> 1  =  recule
		-> 2  =  tourne
		-> 3  =  lat droite
		-> 4  =  lat gauche
*/

void	player_3d_move(t_datas_global *data, int dir)
{
	double	move_speed;

	move_speed = data->player_datas->move_speed;
	if (!dir)
		go(data->player_datas, move_speed, data->map_datas->map, data);
	else if (dir == 1)
		back(data->player_datas, move_speed, data->map_datas->map, data);
	else if (dir == 2)
		rotate(data->player_datas, data->player_datas->rot_speed, data);
	else if (dir == 3)
		lat_right(data->player_datas, move_speed, data);
	else if (dir == 4)
		lat_left(data->player_datas, move_speed, data);
}
