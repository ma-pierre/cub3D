/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:38:32 by irakraki          #+#    #+#             */
/*   Updated: 2022/11/10 17:53:55 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char str [50] = " A0";
	printf("%d\n", ft_isalpha(str[0]));
	printf("%d\n", ft_isalpha(str[1]));
	printf("%d\n", isalpha(str[0]));
	printf("%d\n", isalpha(str[1]));
	return (0);
}*/
