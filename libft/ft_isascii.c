/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:38:17 by irakraki          #+#    #+#             */
/*   Updated: 2022/11/10 17:55:26 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}
/*
int	main()
{
	unsigned char str[50] = "hello";
	printf("%d\n", ft_isascii(str[0]));
	printf("%d\n", isascii(str[0]));
	return (0);
}*/
