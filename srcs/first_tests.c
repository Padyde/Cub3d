#include "all.h"

int first_tests(char **argv, int nb_arg)
{
    int fd;
    char *file;

    if (nb_arg !=2)
        ft_print_error("Error: Arguments\n./Cub3d <path_to_file.cub>\n", NULL);
    file = argv[1];
    if (ft_strlen(file) < 6  || file[ft_strlen(file) - 1] != 'b' || file[ft_strlen(file) - 2] != 'u' || file[ft_strlen(file) - 3] != 'c' || file[ft_strlen(file) - 4] != '.')
        ft_print_error("Error: File name\n./Cub3d <path_to_file.cub>\n", NULL);
    fd = open(file, O_RDONLY);
    if (fd <= 0)
        ft_print_error("Error: File doesn't exist\n", NULL);
    return (fd);
}