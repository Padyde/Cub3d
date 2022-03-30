/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:21:48 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 14:05:41 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	free_all(t_datas_global *all_datas)
{
	if (!all_datas)
		return (0);
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
	if (all_datas->win_ptr)
		mlx_destroy_window(all_datas->mlx_ptr, all_datas->win_ptr);
	return (0);
}

void	malloc_all(t_datas_global *all_datas)
{
	all_datas->map_datas = malloc(sizeof(t_datas_map));
	if (!all_datas->map_datas)
		ft_print_error(ERROR_MALLOC, all_datas);
	all_datas->player_datas = malloc(sizeof(t_datas_player));
	if (!all_datas->player_datas)
		ft_print_error(ERROR_MALLOC, all_datas);
	all_datas->map_datas->north_wall = malloc(sizeof(t_datas_wall));
	if (!all_datas->map_datas->north_wall)
		ft_print_error(ERROR_MALLOC, all_datas);
	all_datas->map_datas->south_wall = malloc(sizeof(t_datas_wall));
	if (!all_datas->map_datas->south_wall)
		ft_print_error(ERROR_MALLOC, all_datas);
	all_datas->map_datas->east_wall = malloc(sizeof(t_datas_wall));
	if (!all_datas->map_datas->east_wall)
		ft_print_error(ERROR_MALLOC, all_datas);
	all_datas->map_datas->west_wall = malloc(sizeof(t_datas_wall));
	if (!all_datas->map_datas->west_wall)
		ft_print_error(ERROR_MALLOC, all_datas);
	all_datas->map_datas->sky = -1;
	all_datas->map_datas->floor = -1;
	all_datas->map_datas->south_wall->ptr = NULL;
	all_datas->map_datas->east_wall->ptr = NULL;
	all_datas->map_datas->north_wall->ptr = NULL;
	all_datas->map_datas->west_wall->ptr = NULL;
	all_datas->tmp = NULL;
	all_datas->tmp1 = NULL;
	all_datas->map_datas->map = NULL;
	all_datas->player_datas->start = -1;
	all_datas->mlx_ptr = mlx_init();
	all_datas->win_ptr = mlx_new_window(all_datas->mlx_ptr, 800, 600, "cub3d");
}

void	print_all(t_datas_global *all_datas)
{
	int	x;

	x = -1;
	printf("North		-> %d\n", all_datas->map_datas->north_wall->size_x);
	printf("East		 -> %d\n", all_datas->map_datas->east_wall->size_x);
	printf("South		-> %d\n", all_datas->map_datas->south_wall->size_x);
	printf("West		 -> %d\n", all_datas->map_datas->west_wall->size_x);
	printf("Floor		-> %d\n", all_datas->map_datas->floor);
	printf("Sky 		-> %d\n", all_datas->map_datas->sky);
	printf("Player x	 -> %f\n", all_datas->player_datas->x);
	printf("Player x	 -> %f\n", all_datas->player_datas->y);
	printf("Player View  -> %d\n", all_datas->player_datas->start);
	printf("Map:\n");
	while (++x < ft_matrixlen(all_datas->map_datas->map))
		printf("%s\n", all_datas->map_datas->map[x]);
}

int	ft_key_hook(int keycode, t_datas_global *all_datas)
{
	if (keycode == ESC)
		ft_print_error(MESSAGE_END_EXIT, all_datas);
	return (0);
}

int	main(int argc, char **argv)
{
	t_datas_global	all_datas;
	int				fd;
	int				tmp;

	fd = first_tests(argv, argc);
	malloc_all(&all_datas);
	convert_datas(fd, &all_datas);
	close(fd);
	if (!all_datas.map_datas->map)
		ft_print_error(ERROR_NOT_MAP, &all_datas);
	tmp = check_map(&all_datas);
	if (tmp == -1)
		ft_print_error(ERROR_WRONG_CHAR, &all_datas);
	else if (tmp == -2)
		ft_print_error(ERROR_WRONG_POS, &all_datas);
	print_all(&all_datas);
	mlx_key_hook(all_datas.win_ptr, ft_key_hook, &all_datas);
	mlx_hook(all_datas.win_ptr, WINDOW_PRESS_EXIT, 0, free_all, &all_datas);
	mlx_loop(all_datas.mlx_ptr);
}
