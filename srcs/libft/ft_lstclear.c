/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:15:17 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 19:16:00 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *list;

	if (del != 0)
		while (*lst != 0)
		{
			del((*lst)->content);
			list = *lst;
			*lst = list->next;
			free(list);
		}
	*lst = 0;
}
