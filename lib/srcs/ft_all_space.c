#include "all.h"

int ft_all_space(char *input)
{
    int i;

    i = -1;
    while (++i < ft_strlen(input))
        if (!ft_isspace(input[i]))
            return (1);
    return (0);
}