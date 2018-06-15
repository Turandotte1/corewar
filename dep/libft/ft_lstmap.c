/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:27:51 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 17:03:07 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*list;
	t_list	*start;

	list = NULL;
	while (lst)
	{
		temp = (*f)(lst);
		if (!list)
		{
			if (!(list = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			start = list;
		}
		else
		{
			if (!(list->next = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			list = list->next;
		}
		lst = lst->next;
	}
	return (start);
}
