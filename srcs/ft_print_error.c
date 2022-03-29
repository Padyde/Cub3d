#include "all.h"

void    ft_print_error(char *output, t_datas_global *all_datas)
{
    free_all(all_datas);
    write(2, output, ft_strlen(output));
    exit (1);
}