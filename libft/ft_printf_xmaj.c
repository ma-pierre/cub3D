/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xmaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:53:46 by irakraki          #+#    #+#             */
/*   Updated: 2023/09/13 12:46:19 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_printf_xmaj(unsigned long n)
{
	int				i;
	const char		*maj;
	char			c;

	i = 0;
	maj = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_printf_xmaj(n / 16);
	c = maj[n % 16];
	i += ft_printf_c(c);
	return (i);
}
