/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:54:04 by irakraki          #+#    #+#             */
/*   Updated: 2023/09/13 12:46:01 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_printf_u(unsigned int n)
{
	int				i;

	i = 0;
	if (n >= 10)
		i += ft_printf_u(n / 10);
	i += ft_printf_c(n % 10 + 48);
	return (i);
}
