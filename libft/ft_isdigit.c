/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:03:18 by irakraki          #+#    #+#             */
/*   Updated: 2022/11/10 17:56:06 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char str [50] = "1r2@";
	printf("%d\n", ft_isdigit(str[0]));
	printf("%d\n", ft_isdigit(str[1]));
	printf("%d\n", ft_isdigit(str[2]));
	printf("%d\n", isdigit(str[0]));
	printf("%d\n", isdigit(str[1]));
	printf("%d\n", isdigit(str[2]));
	return (0);
}*/
