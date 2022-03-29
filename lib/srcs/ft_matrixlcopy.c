#include "all.h"

char	**ft_matrixlcpy(char **matrix_in, int nb_line)
{
	char	**matrix_return;
	int		x;

	matrix_return = malloc(sizeof(char *) * (nb_line + 2));
	if (!matrix_return)
		return (NULL);
	x = -1;
	while (++x < nb_line)
	{
		matrix_return[x] = malloc(sizeof(char) * ft_strlen(matrix_in[x]) + 1);
		if (!matrix_return[x])
			return (NULL);
		ft_strlcpy(matrix_return[x], matrix_in[x], ft_strlen(matrix_in[x]) + 1);
	}
	matrix_return[x] = NULL;
	return (matrix_return);
}