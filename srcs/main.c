/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:21:48 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 14:47:33 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	ft_exit(t_datas_global *all_datas)
{
	free_all(all_datas);
	if (all_datas->mlx_ptr)
	{
		mlx_destroy_window(all_datas->mlx_ptr, all_datas->win_ptr);
		write(1, MESSAGE_END_EXIT, ft_strlen(MESSAGE_END_EXIT));
		exit (0);
	}
	return (0);
}

/*
all_datas->player_datas->pl_delta_x = cos(all_datas->player_datas->pl_angle);
all_datas->player_datas->pl_delta_y = sin(all_datas->player_datas->pl_angle);

all_datas->player_datas->pl_angle = 3*PI/2; haut
all_datas->player_datas->pl_angle = PI/2; bas
all_datas->player_datas->pl_angle = PI*2; droite
all_datas->player_datas->pl_angle = PI; gauche
pour le nord
float	dir_x = 0;
float	dir_y = -1;

sud
float	dir_x = 0;
float	dir_y = 1;

ouest
float	dir_x = -1;
float	dir_y = 0;

est
float	dir_x = 1;
float	dir_y = 0;
*/

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
	printf("Player View  -> %f\n", all_datas->player_datas->dir_x);
	printf("Map:\n");
	while (++x < ft_matrixlen(all_datas->map_datas->map))
		printf("%s\n", all_datas->map_datas->map[x]);
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
	mlx_hook(all_datas.win_ptr, 2, 0, ft_key_hook, &all_datas);
	mlx_hook(all_datas.win_ptr, WINDOW_PRESS_EXIT, 0, ft_exit, &all_datas);
	create_wall(&all_datas);
	mlx_loop(all_datas.mlx_ptr);
}
