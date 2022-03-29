# include "all.h"

void    ft_free_mat(char **mat)
{
    int x;

    x = -1;
    while (++x < ft_matrixlen(mat))
        free(mat[x]);
    free(mat);
}