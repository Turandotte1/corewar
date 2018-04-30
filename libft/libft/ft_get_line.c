/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:17:10 by mipham            #+#    #+#             */
/*   Updated: 2017/11/13 14:18:43 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *s, int *i)
{
	int		j;
	char	*s2;

	j = *i;
	while (s[j])
	{
		if (s[j] == '\n')
			break ;
		++j;
	}
	s2 = ft_strndup(s + *i, j - *i);
	*i = j + 1;
	return (s2);
}

char	*ft_cut_first_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	str = ft_strsub(str, 0, i);
	return (str);
}

char	*ft_point_to_next_line(char *str)
{
	char	*next;

	next = ft_strchr(str, '\n');
	if (next && next + 1)
		str = next + 1;
	else
		str = "\0";
	return (str);
}
