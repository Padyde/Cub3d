/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:45:12 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 14:46:40 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	free_all(t_datas_global *all_datas)
{
	if (!all_datas)
		return ;
	if (all_datas->player_datas)
		free(all_datas->player_datas);
	if (all_datas->map_datas->east_wall)
		free(all_datas->map_datas->east_wall);
	if (all_datas->map_datas->north_wall)
		free(all_datas->map_datas->north_wall);
	if (all_datas->map_datas->west_wall)
		free(all_datas->map_datas->west_wall);
	if (all_datas->map_datas->south_wall)
		free(all_datas->map_datas->south_wall);
	if (all_datas->map_datas->map)
		ft_free_mat(all_datas->map_datas->map);
	if (all_datas->map_datas)
		free(all_datas->map_datas);
	if (all_datas->tmp)
		free(all_datas->tmp);
	if (all_datas->tmp1)
		ft_free_mat(all_datas->tmp1);
}

void	*malloc_test(void *all, int nb, t_datas_global *all_datas)
{
	all = malloc(nb);
	if (!all)
		ft_print_error(ERROR_MALLOC, all_datas);
	return (all);
}

void	malloc_all_2(t_datas_global *all_datas)
{
	all_datas->map_datas = (t_datas_map *)malloc_test(all_datas->map_datas, \
		sizeof(t_datas_map), all_datas);
	all_datas->display_datas = (t_datas_display *)malloc_test(\
		all_datas->display_datas, sizeof(t_datas_display), all_datas);
	all_datas->player_datas = (t_datas_player *)malloc_test(\
		all_datas->player_datas, sizeof(t_datas_player), all_datas);
	all_datas->map_datas->north_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->north_wall, sizeof(t_datas_wall), all_datas);
	all_datas->map_datas->south_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->south_wall, sizeof(t_datas_wall), all_datas);
	all_datas->map_datas->east_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->east_wall, sizeof(t_datas_wall), all_datas);
	all_datas->map_datas->west_wall = (t_datas_wall *)malloc_test(\
		all_datas->map_datas->west_wall, sizeof(t_datas_wall), all_datas);
}

void	malloc_all(t_datas_global *all_datas)
{
	malloc_all_2(all_datas);
	all_datas->map_datas->sky = -1;
	all_datas->map_datas->floor = -1;
	all_datas->map_datas->south_wall->ptr = NULL;
	all_datas->map_datas->east_wall->ptr = NULL;
	all_datas->map_datas->north_wall->ptr = NULL;
	all_datas->map_datas->west_wall->ptr = NULL;
	all_datas->tmp = NULL;
	all_datas->tmp1 = NULL;
	all_datas->map_datas->map = NULL;
	all_datas->player_datas->dir_x = -2;
	all_datas->player_datas->move_speed = 0.2;
	all_datas->player_datas->rot_speed = 0.2;
	all_datas->mlx_ptr = mlx_init();
	all_datas->win_ptr = mlx_new_window(all_datas->mlx_ptr, SCREEN_WIGHT, \
		SCREEN_HEIGHT, "cub3D");
	all_datas->display_datas->ptr = mlx_new_image(all_datas->mlx_ptr, \
		SCREEN_WIGHT, SCREEN_HEIGHT);
	all_datas->display_datas->addr = mlx_get_data_addr(\
		all_datas->display_datas->ptr, &all_datas->display_datas->bpp, \
		&all_datas->display_datas->size_line, \
		&all_datas->display_datas->endian);
}
