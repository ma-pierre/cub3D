/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:53:56 by irakraki          #+#    #+#             */
/*   Updated: 2023/09/13 12:46:09 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_printf_x(unsigned long n)
{
	int				i;
	const char		*min;
	char			c;

	i = 0;
	min = "0123456789abcdef";
	if (n >= 16)
		i += ft_printf_x(n / 16);
	c = min[n % 16];
	i += ft_printf_c(c);
	return (i);
}
