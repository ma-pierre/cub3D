/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:34:31 by irakraki          #+#    #+#             */
/*   Updated: 2022/11/25 20:57:40 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ds;
	int		i;

	i = 0;
	ds = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ds)
		return (NULL);
	while (s[i])
	{
		ds[i] = s[i];
		i++;
	}
	ds[i] = '\0';
	return (ds);
}
/*
int	main(void)
{
	char * s = "hello";
	printf("%s\n", ft_strdup(s));
	return (0);
}
*/
