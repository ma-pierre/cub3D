/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:28:49 by irakraki          #+#    #+#             */
/*   Updated: 2022/12/07 20:22:57 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_int(int nb)
{
	unsigned int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int		len;
	char				*dst;
	char				neg;

	neg = '\0';
	if (n < 0)
		neg = '-';
	len = ft_len_int(n);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (len != 0)
	{
		if (n < 0)
			dst[--len] = -(n % 10) + 48;
		else
			dst[--len] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg)
		dst[len] = neg;
	return (dst);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-42));
	return (0);
}
*/
