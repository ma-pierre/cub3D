/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:18:47 by irakraki          #+#    #+#             */
/*   Updated: 2022/11/11 14:27:19 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*test;
	size_t	i;

	test = (char *)s;
	i = 0;
	while (i < n)
	{
		test[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	unsigned char s[] = "hello";
	unsigned char t[] = "hello";
	ft_bzero(s, 2);
	bzero(t, 2);
	printf("%s\n", (s));
	printf("%s\n", (t));
	return (0);
}*/
