/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:14:15 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/04/08 14:43:49 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "lib.h"
# include "all_inc.h"

typedef struct s_datas_map		t_datas_map;
typedef struct s_datas_wall		t_datas_wall;
typedef struct s_datas_player	t_datas_player;
typedef struct s_datas_display	t_datas_display;
typedef struct s_datas_global	t_datas_global;
typedef struct s_ray			t_ray;
typedef struct s_vert_line		t_vert_line;

struct s_datas_player
{
	float	x;
	float	y;
	float	pl_angle;
	float	pl_delta_x;
	float	pl_delta_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;
	double	plane_x;
	double	plane_y;
};

struct s_datas_wall
{
	int		size_x;
	int		size_y;
	void	*ptr;
	void	*addr;
	int		size_line;
	int		bpp;
	int		endian;
};

struct s_datas_display
{
	int		size_line;
	int		bpp;
	int		endian;
	void	*ptr;
	void	*addr;
};

struct s_datas_map
{
	char			**map;
	t_datas_wall	*north_wall;
	t_datas_wall	*south_wall;
	t_datas_wall	*west_wall;
	t_datas_wall	*east_wall;
	int				floor;
	int				sky;
};

struct s_datas_global
{
	t_datas_map		*map_datas;
	t_datas_player	*player_datas;
	t_datas_display	*display_datas;
	void			*mlx_ptr;
	void			*win_ptr;
	int				tmp2;
	char			*tmp;
	char			**tmp1;
};

struct s_ray
{
	int				x;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	double			cam_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_dist;
	int				line_heigt;
	int				draw_start;
	int				draw_end;
	void			*img_ptr;
	double			wall_x;
	int				tex_x;
	int				tex_h;
	int				tex_w;
	int				tex_y;
	double			step;
	double			tex_pos;
	t_datas_wall	*wall;
};

struct s_vert_line
{
	int				i;
	int				x;
	unsigned int	colors;
	int				*ptr;
};

void	copy_the_other(char *params, int *val, t_datas_global *all_datas);
void	convert_datas(int fd, t_datas_global *datas_map);
void	free_all(t_datas_global *all_datas);
void	malloc_all(t_datas_global *all_datas);
void	convert_map(char *new_line, t_datas_global *datas_map);
void	ft_print_error(char *output, t_datas_global *all_datas);
void	copy_the_wall(t_datas_global *all_datas, char *cp, t_datas_wall *wall);
void	act_wall(t_datas_global *all_datas, char **mat);

void	create_wall(t_datas_global *data);
void	init_ray_var(t_ray *data_r, t_datas_global *data);
void	init_line_size(t_ray *data_r, t_datas_global *data);
void	init_img(t_ray *data_r, t_datas_wall *data_w);
void	init_tex(t_ray *data_r, t_datas_global *data);
void	draw_2d_ray(t_datas_global *data);
void	draw_vertical_line(t_datas_global *data, t_ray *data_r);
void	player_3d_move(t_datas_global *data, int dir);
void	def_dirs(t_datas_player *player, int val1, int val2, int val3);
void	draw_rotarion(t_datas_global *data);
void	go(t_datas_player *val1, double val2, char **map, t_datas_global *data);
void	back(t_datas_player *val1, double val2, char **map, \
	t_datas_global *data);
void	rotate(t_datas_player *val1, double val2, t_datas_global *data);
void	lat_right(t_datas_player *v1, double v2, t_datas_global *data);
void	lat_left(t_datas_player *v1, double v2, t_datas_global *data);

char	*get_next_line(int fd);

int		check_map(t_datas_global *all_datas);
int		check_char(char x);
int		check_num(char *string, t_datas_global *all_datas);
int		first_tests(char **argv, int nb_arg);
int		give_me_wall(char *line, t_datas_global *all_datas);
int		ft_key_hook(int keycode, t_datas_global *all_datas);

double	wd(int val1, double val2, double val3, double val4);
double	ray(t_datas_player *val1, int val2, double val3);
double	delta(double val1, double val2);
double	dpx(t_datas_player *val1, double val2, int val3);
double	dpy(t_datas_player *val1, double val2, int val3, double val4);

#endif
