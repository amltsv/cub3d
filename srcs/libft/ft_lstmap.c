/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:14:52 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 19:16:01 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *list;
	t_list *tmp;

	list = 0;
	while (lst != 0)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == 0)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, tmp);
		lst = lst->next;
	}
	return (list);
}
