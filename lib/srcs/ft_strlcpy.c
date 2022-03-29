#include "all.h"

int	ft_strlcpy(char *dst, const char *src, int siz)
{
	int	i;
	int	lenSrc;

	i = 0;
	lenSrc = ft_strlen(src);
	if (!siz)
		return (lenSrc);
	while (src[i] && i < (siz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lenSrc);
}