/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:54:43 by irakraki          #+#    #+#             */
/*   Updated: 2023/09/13 14:34:15 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_id(int n)
{
	int long	nbr;
	int			i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_printf_c('-');
	}
	if (nbr >= 10)
		i += ft_printf_id(nbr / 10);
	i += ft_printf_c(nbr % 10 + 48);
	return (i);
}
