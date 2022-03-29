#include "all.h"

void copy_the_wall(t_datas_global *all_datas, char *to_copy, t_datas_wall *wall)
{
    int             fd;

    if (wall->ptr)
        ft_print_error("Error: Two images for a wall\n", all_datas);
    if (ft_strlen(to_copy) <=4 || to_copy[ft_strlen(to_copy) - 1] != 'M' || to_copy[ft_strlen(to_copy) - 2] != 'P' || to_copy[ft_strlen(to_copy) - 3] != 'X' || to_copy[ft_strlen(to_copy) - 4] != '.')
        ft_print_error("Error: Wrong type for image\n", all_datas);
    fd = open (to_copy, O_RDONLY);
    if (fd <= 0)
        ft_print_error("Error: image doesn't exist\n", all_datas);
    close(fd);
    wall->ptr = mlx_xpm_file_to_image(all_datas->mlx_ptr, to_copy, &wall->size_x, &wall->size_y);
}

void    copy_the_other(char *params, int *val, t_datas_global *all_datas)
{
    char    **mat;
    int     output;

    if (*val != -1)
        ft_print_error("Error: Two images for the floor/sky\n", all_datas);
    mat = ft_split(params, ',');
    if (ft_matrixlen(mat) != 3)
    {
        if (mat)
            ft_free_mat(mat);
        ft_print_error("Error: Invalid number of colors for the rgb\n", all_datas);
    }
    output = 0;
    output += check_num(mat[0], all_datas) * 255 * 255;
    output += check_num(mat[1], all_datas) * 255;
    output += check_num(mat[2], all_datas);
    *val = output;
    ft_free_mat(mat);
}