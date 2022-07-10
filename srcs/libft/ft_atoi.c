/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:15:46 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 19:15:55 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *src, int *index)
{
	long int	result;
	int			negative;

	result = 0;
	negative = 1;
	while (src[*index] != 0 && ((src[*index] >= 9 && src[*index] <= 13) ||
				src[*index] == 32))
		*index += 1;
	if (src[*index] == '+' || src[*index] == '-')
	{
		if (src[*index] == '-')
			negative = -1;
		*index += 1;
	}
	while (src[*index] != 0 && (src[*index] >= 48 && src[*index] <= 57))
	{
		result = (result * 10) + (src[*index] - '0');
		*index += 1;
	}
	return (result * negative);
}
