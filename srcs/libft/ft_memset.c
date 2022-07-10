/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:14:17 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 20:53:29 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*tmp;
	char	number;

	tmp = (char *)ptr;
	number = (char)value;
	while (num-- != 0)
		*tmp++ = number;
	return (ptr);
}
