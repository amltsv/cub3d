/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:14:12 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 20:53:38 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_puterror(char *msg)
{
	if (!msg)
		return ;
	while (*msg)
	{
		ft_putchar(*msg);
		msg++;
	}
}

int			ft_isspace(char c)
{
	if (c == 9 || c == 10 || c == 32 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}
