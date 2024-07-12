/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:54:31 by irakraki          #+#    #+#             */
/*   Updated: 2023/09/13 12:45:51 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_printf_p(unsigned long n)
{
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_printf_x(n) + 2);
}
