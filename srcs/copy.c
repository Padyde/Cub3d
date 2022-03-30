/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:00 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:22:01 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	copy_the_wall(t_datas_global *all_datas, char *to_copy, t_datas_wall *wall)
{
	int	fd;

	if (wall->ptr)
		ft_print_error(ERROR_TOO_MANY_IMG, all_datas);
	if (ft_strlen(to_copy) <= 4 || to_copy[ft_strlen(to_copy) - 1] != 'M' || to_copy[ft_strlen(to_copy) - 2] != 'P' || to_copy[ft_strlen(to_copy) - 3] != 'X' || to_copy[ft_strlen(to_copy) - 4] != '.')
		ft_print_error(ERROR_WRONG_TYPE_IMG, all_datas);
	fd = open (to_copy, O_RDONLY);
	if (fd <= 0)
		ft_print_error(ERROR_IMG_NOT_EXIST, all_datas);
	close(fd);
	wall->ptr = mlx_xpm_file_to_image(all_datas->mlx_ptr, to_copy, &wall->size_x, &wall->size_y);
}

void	copy_the_other(char *params, int *val, t_datas_global *all_datas)
{
	char	**mat;

	if (*val != -1)
		ft_print_error(ERROR_MORE_COLOR, all_datas);
	mat = ft_split(params, ',');
	if (ft_matrixlen(mat) != 3)
	{
		ft_free_mat(mat);
		ft_print_error(ERROR_INV_NUMBER_COLOR, all_datas);
	}
	*val = 0;
	*val += check_num(mat[0], all_datas) * 255 * 255;
	*val += check_num(mat[1], all_datas) * 255;
	*val += check_num(mat[2], all_datas);
	ft_free_mat(mat);
}
