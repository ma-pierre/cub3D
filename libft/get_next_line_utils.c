/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakraki <irakraki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:04:00 by mapierre          #+#    #+#             */
/*   Updated: 2024/06/26 20:58:17 by irakraki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_n(char *memo)
{
	int	i;

	i = 0;
	if (memo == NULL)
		return (-1);
	while (memo[i] != '\0')
	{
		if (memo[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
