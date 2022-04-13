#include "all.h"

void	draw_ray(t_datas_global *data)
{
	int		color = 0xFF0000;
	float	i = -1;
	float	x = (8 * 10) / 2 + 4; // +8 == pixel du player // 8 * nb de pixel dans un mur en X// * 10 taille de la map en X
	float	y = (8 * 10) / 2 + 4; // +8 == pixel du player // 8 * nb de pixel dans un mur en Y // * 10 taille de la map en Y

	while (++i < 12)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
			(x + (data->player_datas->dir_x * i)), (y + (data->player_datas->dir_y * i)), color);
}

void	draw_player(t_datas_global *data)
{
	int	x = (8 * 10) / 2;
	int	y = (8 * 10) / 2;
	int		color = 0xFF0000;

	while (y < ((8 * 10) / 2) + 8) // +8 == pixel du player // 8 * nb de pixel dans un mur en Y // * 10 taille de la map en Y
	{
		x = (8 * 10) / 2;
		while (x < ((8 * 10) / 2) + 8) // +8 == pixel du player // 8 * nb de pixel dans un mur en X// * 10 taille de la map en X
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			x ++;
		}
		y ++;
	}
}

void	draw_map(t_datas_global *data)
{
	int	j;
	int	i;
	int	start_j = 0;
	int	start_i = 0;
	int	x = 0;
	int	y = 0;
	int x_add;
	int y_add;
	int	color;

	if (data->player_datas->x - 5 < 0)
	{
		x_add = 0;
		start_j = abs(((int)data->player_datas->x - 5));
	}
	else
		x_add = data->player_datas->x- 5;
	if (data->player_datas->y - 5 < 0)
	{
		y_add = 0;
		start_i = abs(((int)data->player_datas->y - 5));
	}
	else
		y_add = data->player_datas->y- 5;
	y = 0;
	while (y < 80)
	{
		x = 0;
		while (x < 80)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	i = 0;
	while (i < 10 - start_i)
	{
		j = 0;
		while (j < 10 - start_j)
		{
			if (i + y_add < ft_matrixlen(data->map_datas->map) && j + x_add < ft_strlen(data->map_datas->map[i + y_add])) // y x
			{
				if (data->map_datas->map[i + y_add][j + x_add] == '1')
					color = 0xFFFFFFF;
				else if (data->map_datas->map[i + y_add][j + x_add] == '0')
					color = 0x000000;
				else
					color = 0xFF0000;
				y = (i) * 8;
				while (y < 8 * (i + 1))
				{
					x = (j) * 8;
					while (x < 8 * (j + 1))
					{
						mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + (start_j * 8), y + (start_i * 8), color);
						x++;
					}
					y++;
				}
			}
			j++;
		}
		i++;
	}
	draw_ray(data);
	draw_player(data);
}

 /*
void	draw_map(t_ray *data_r, t_datas_global *data)
{
	int	j = data->player_datas->x - 3;
	int	i = data->player_datas->y - 3;
	//int	jj = data->player_datas->x - 3;
	//int	ii = data->player_datas->y - 3;
	int	x = 0;
	int	y = 0;
	int	color = 0xFFFFFFF;
	draw_ray(data_r, data);
	draw_player(data);
	while (i < data->player_datas->y + 3)
	{
		j = data->player_datas->x - 3;
		while (j < data->player_datas->x + 3)
		{
			if (j >= 0 && i >= 0 && i < ft_matrixlen(data->map_datas->map) && j < ft_strlen(data->map_datas->map[i])) // y x
			{
				if (data->map_datas->map[i][j] == '1')
				{
					y = i * 8;
					while (y < 8 * (i + 1))
					{
						x = j * 8;
						while (x < 8 * (j + 1))
						{
							mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
							x++;
						}
						y++;
					}
				}
			}
			else
			{
				y = i * 8;
				while (y < 8 * (i + 1))
				{
					x = j * 8;
					while (x < 8 * (j + 1))
					{
						printf("Y: %d R_y: %d X: %d R_x: %d\n", y, 8 * (i + 1), x, 8 * (j + 1));
						mlx_pixel_put(data->mlx_ptr, data->win_ptr, abs(x), abs(y), 0x0000000);
						x++;
					}
					y++;
				}
			}
			j++;
		}
		i++;
	}
}
*/

/*
if (j >= 0 && i >= 0 && i < ft_matrixlen(data->map_datas->map) && j < ft_strlen(data->map_datas->map[i]) && data->map_datas->map[i][j] == '1') // y x
{
	printf("I: %d J: %d X: %f Y: %f\n", i, j, data->player_datas->x, data->player_datas->y);
	if (ii < 0)
	{
		y = i * 8 - ((ii - 1) * 8);
		while (y < (8 * (i + 1)) - ((ii - 1) * 8))
		{
			if (jj < 0)
			{
				x = j * 8 - ((jj - 1  )* 8);
				while (x < (8 * (j + 1)) - ((jj - 1) * 8))
				{
					mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
					x++;
				}
				y++;
			}
			else
			{
				x = j * 8;
				while (x < 8 * (j + 1))
				{
					mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
					x++;
				}
				y++;
			}

		}
	}
	else
	{
		y = i * 8;
		while (y < (8 * (i + 1)))
		{
			if (jj < 0)
			{
				x = j * 8 - ((jj - 1) * 8);
				while (x < (8 * (j + 1)) - ((jj - 1) * 8))
				{
					mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
					x++;
				}
				y++;
			}
			else
			{
				x = j * 8;
				while (x < 8 * (j + 1))
				{
					mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
					x++;
				}
				y++;
			}

		}
	}

}*/
