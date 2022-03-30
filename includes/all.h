/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoorickx <hugoorickx@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:14:15 by hugoorickx        #+#    #+#             */
/*   Updated: 2022/03/30 11:38:27 by hugoorickx       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "lib.h"
# include "all_inc.h"

typedef struct s_datas_map		t_datas_map;
typedef struct s_datas_wall		t_datas_wall;
typedef struct s_datas_player	t_datas_player;
typedef struct s_datas_global	t_datas_global;

struct s_datas_player
{
	float	x;
	float	y;
	int		start;
};

struct s_datas_wall
{
	int		size_x;
	int		size_y;
	void	*ptr;
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
	void			*mlx_ptr;
	void			*win_ptr;
	char			*tmp;
	char			**tmp1;
};

void	copy_the_other(char *params, int *val, t_datas_global *all_datas);
void	convert_datas(int fd, t_datas_global *datas_map);
void	free_all(t_datas_global *all_datas);
void	malloc_all(t_datas_global *all_datas);
void	convert_map(char *new_line, t_datas_global *datas_map);
void	ft_print_error(char *output, t_datas_global *all_datas);
void	copy_the_wall(t_datas_global *datas, char *to_copy, t_datas_wall *wall);

char	*get_next_line(int fd);

int		check_map(t_datas_global *all_datas);
int		check_char(char x);
int		check_num(char *string, t_datas_global *all_datas);
int		first_tests(char **argv, int nb_arg);
int		give_me_wall(char *line, t_datas_global *all_datas);

#endif