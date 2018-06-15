/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublelink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:52:23 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 19:40:52 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_doublelink_add(t_double *list, void *content,
								size_t cont_size)
{
	t_node		*new_elem;

	new_elem = (t_node *)malloc(sizeof(t_node));
	if (new_elem == NULL)
		return ;
	ft_bzero(new_elem, sizeof(t_node));
	new_elem->content = (void *)malloc(cont_size);
	if (new_elem->content == NULL)
	{
		free(new_elem);
		return ;
	}
	ft_memcpy(new_elem->content, content, cont_size);
	new_elem->next = NULL;
	new_elem->prev = NULL;
	if (list->head == NULL)
		list->head = new_elem;
	else
	{
		list->tail->next = new_elem;
		new_elem->prev = list->tail;
	}
	list->tail = new_elem;
	list->length++;
}

void			ft_doublelink_add_head(t_double *list, void *content,
				size_t cont_size)
{
	t_node		*new_elem;

	if ((new_elem = (t_node *)malloc(sizeof(t_node))) == NULL)
		return ;
	ft_bzero(new_elem, sizeof(t_node));
	new_elem->content = (void *)malloc(cont_size);
	if (new_elem->content == NULL)
	{
		free(new_elem);
		return ;
	}
	ft_memcpy(new_elem->content, content, cont_size);
	if (list->tail == NULL && list->head == NULL)
	{
		list->tail = new_elem;
		list->head = new_elem;
	}
	else
	{
		list->head->prev = new_elem;
		new_elem->next = list->head;
		list->head = new_elem;
	}
	list->length++;
}

void			ft_doublelink_tail(t_double *list, void *content,
				size_t cont_size)
{
	t_node		*new_elem;

	new_elem = (t_node *)malloc(sizeof(t_node));
	if (new_elem == NULL)
		return ;
	ft_bzero(new_elem, sizeof(t_node));
	new_elem->content = (void *)malloc(cont_size);
	if (new_elem->content == NULL)
	{
		free(new_elem);
		return ;
	}
	ft_memcpy(new_elem->content, content, cont_size);
	if (list->tail == NULL)
	{
		new_elem->prev = NULL;
		list->head = new_elem;
	}
	else
	{
		list->tail->next = new_elem;
		new_elem->prev = list->tail;
	}
	list->tail = new_elem;
	list->length++;
}
