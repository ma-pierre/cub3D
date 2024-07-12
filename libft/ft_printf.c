/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:51:52 by irakraki          #+#    #+#             */
/*   Updated: 2023/09/13 14:33:11 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv(char c, va_list ap)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(ap, int)));
	else if (c == 's')
		return (ft_printf_s(va_arg(ap, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_printf_id(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (ft_printf_c('%'));
	else if (c == 'x')
		return (ft_printf_x(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_printf_xmaj(va_arg(ap, unsigned int)));
	else if (c == 'p')
		return (ft_printf_p(va_arg(ap, unsigned long)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		c_conv;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			c_conv = 0;
			c_conv = ft_conv(format[++i], ap);
			if (c_conv == -1)
				return (0);
			count += c_conv;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
