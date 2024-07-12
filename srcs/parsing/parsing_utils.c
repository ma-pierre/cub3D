#include "cub3D.h"

int	is_white_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || \
			c == '\v' || c == '\r');
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}


int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	next_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\f' || \
			c == '\v' || c == '\r');
}
