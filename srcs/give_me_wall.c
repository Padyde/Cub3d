#include "all.h"

int give_me_wall(char *line, t_datas_global *all_datas)
{
    char **mat;

    mat = ft_split_up(line);
    all_datas->tmp1 = mat;
    if (ft_matrixlen(mat) == 0)
       return (0);
    else if (ft_matrixlen(mat) == 1)
        ft_print_error("Error: Datas missing\n", all_datas);
    else if (ft_matrixlen(mat) > 2)
        ft_print_error("Error: too many datas\n", all_datas);
    if (ft_strlen(mat[0]) == 2 || ft_strlen(mat[0]) == 1)
    {
        if (!ft_strcmp(mat[0], "NO"))
            copy_the_wall(all_datas, mat[1], all_datas->map_datas->north_wall);
        else if (!ft_strcmp(mat[0], "SO"))
            copy_the_wall(all_datas, mat[1], all_datas->map_datas->south_wall);
        else if (!ft_strcmp(mat[0], "EA"))
            copy_the_wall(all_datas, mat[1], all_datas->map_datas->east_wall);
        else if (!ft_strcmp(mat[0], "WE"))
            copy_the_wall(all_datas, mat[1], all_datas->map_datas->west_wall);
        else if (!ft_strcmp(mat[0], "F"))
            copy_the_other(mat[1], &all_datas->map_datas->floor, all_datas);
        else if (!ft_strcmp(mat[0], "C"))
            copy_the_other(mat[1], &all_datas->map_datas->sky, all_datas);
        else
            ft_print_error("Error: Data not valid\n", all_datas);
    }
    else
        ft_print_error("Error: Data not valid\n", all_datas);
    ft_free_mat(mat);
    all_datas->tmp1 = NULL;
    return (1);
}