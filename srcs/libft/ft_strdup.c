/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:14:01 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 19:16:03 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	if ((dst = malloc(sizeof(char) * (ft_strlen(s1) + 1))) == 0)
		return (0);
	while (s1[i] != 0)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
