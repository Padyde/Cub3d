#include "all.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}