/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:14:38 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 03:35:57 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_reader		*ft_init(const int fd)
{
	t_reader	*init;

	if (!(init = (t_reader *)malloc(sizeof(t_reader))))
		return (NULL);
	init->buf = ft_strnew(BUFF_LEN);
	init->fd = fd;
	return (init);
}

t_reader		*ft_wtf_buffer(t_list **list, const int fd)
{
	t_list		*current;
	t_reader	*reader;

	if (!list)
		return (NULL);
	current = *list;
	while (current)
	{
		if (((t_reader *)current->content)->fd == fd)
			return ((t_reader *)current->content);
		current = current->next;
	}
	if (!(reader = ft_init(fd)))
		return (NULL);
	current = ft_lstnew(reader, sizeof(t_reader));
	free(reader);
	reader = NULL;
	((t_reader *)current->content)->fd = fd;
	ft_lstadd(list, current);
	return ((t_reader *)current->content);
}

char			**ft_swap_swap(char **line, char *buf)
{
	char		*temp;

	if (!(line))
		return (NULL);
	temp = ft_strjoin(*line, buf);
	ft_strdel(line);
	*line = ft_strdup(temp);
	ft_strdel(&temp);
	ft_strclr(buf);
	return (line);
}

size_t			ft_line(t_reader **reader, char **line)
{
	char	*end_of_line;
	int		banana;
	char	*temp;

	banana = 1;
	temp = NULL;
	while (!(end_of_line = ft_strchr((*reader)->buf, '\n')) && banana > 0)
	{
		ft_swap_swap(line, (*reader)->buf);
		if ((banana = read((*reader)->fd, (*reader)->buf, BUFF_LEN)) < 1
				&& !(**line))
			return (banana);
	}
	if (end_of_line &&
		!(temp = ft_strsub((*reader)->buf, 0, end_of_line - (*reader)->buf)))
		return (-1);
	if (end_of_line && !(line = ft_swap_swap(line, temp)))
		return (-1);
	ft_strdel(&temp);
	temp = end_of_line ? ft_strdup(end_of_line + 1) : ft_strnew(0);
	ft_strclr((*reader)->buf);
	ft_strcat((*reader)->buf, temp);
	ft_strdel(&temp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_reader		*reader;
	size_t			banana;

	if (!line)
		return (-1);
	*line = ft_strnew(0);
	if (!(*line))
		return (-1);
	if (!(reader = ft_wtf_buffer(&list, fd)))
	{
		ft_strdel(line);
		return (-1);
	}
	if ((banana = ft_line(&reader, line)) < 1)
		ft_strdel(line);
	return (banana);
}
