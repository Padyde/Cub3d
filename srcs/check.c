/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:05 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 14:32:27 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	check_num(char *string, t_datas_global *all_datas)
{
	int	output;

	output = ft_atoi(string);
	if (ft_strlen(string) == 1 && !ft_isdigit(string[0]))
		ft_print_error(ERROR_WRONG_VALUE, all_datas);
	else if (output == -1 && ft_strlen(string) > 2)
		ft_print_error(ERROR_RBG_MAX_INT, all_datas);
	else if (output < 0)
		ft_print_error(ERROR_RBG_NEG, all_datas);
	else if (output > 255)
		ft_print_error(ERROR_RGB_255, all_datas);
	else if (output == 0 && ft_strlen(string) > 1)
		ft_print_error(ERROR_RGB_MIN_INT, all_datas);
	return (output);
}

int	check_char(char x)
{
	return (x != '\0' && x != ' ' && x != '0' && x != '1'
		&& x != 'N' && x != 'S' && x != 'E' && x != 'W');
}

int	check_map(t_datas_global *all_datas)
{
	int		x;
	int		y;
	char	**map;

	y = -1;
	map = all_datas->map_datas->map;
	while (++y < ft_matrixlen(map))
	{
		x = -1;
		while (x++ < ft_strlen(map[y]))
			if (check_char(map[y][x]))
				return (-1);
	}
	y = -1;
	while (++y < ft_matrixlen(map))
	{
		x = -1;
		while (x++ < ft_strlen(map[y]))
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
			{
				if ((x == 0 || y == 0 || x + 1 == ft_strlen(map[y]) || x >= ft_strlen(map[y + 1]) || x >= ft_strlen(map[y - 1]) || y + 1 == ft_matrixlen(map)) || check_char(map[y][x + 1]) || check_char(map[y][x - 1]) || check_char(map[y + 1][x]) || check_char(map[y - 1][x]))
					return (-2);
				if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
				{
					if (all_datas->player_datas->start > -1)
						ft_print_error(ERROR_MORE_PLAYER, all_datas);
					all_datas->player_datas->x = (float)x;
					all_datas->player_datas->y = (float)y;
					if (map[y][x] == 'N')
						all_datas->player_datas->start = 1;
					if (map[y][x] == 'E')
						all_datas->player_datas->start = 2;
					if (map[y][x] == 'S')
						all_datas->player_datas->start = 3;
					if (map[y][x] == 'W')
						all_datas->player_datas->start = 4;
				}
			}
		}
	}
	if (all_datas->player_datas->start == -1)
		ft_print_error(ERROR_NO_PLAYER, all_datas);
	return (1);
}
