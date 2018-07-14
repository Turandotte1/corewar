/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:35:31 by mipham            #+#    #+#             */
/*   Updated: 2018/07/14 16:52:08 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		size = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (*s1)
			res[i++] = *s1++;
		while (*s2)
			res[i++] = *s2++;
		res[i] = '\0';
		return (res);
	}
	return (0);
}

char		*ft_strjoin_np(char *s1, char *s2)
{
	int		l;
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		++i;
	l = 0;
	while (s2[l])
		++l;
	if (!(str = (char*)malloc(i + l + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	l = -1;
	str += i;
	while (s2[++l])
		str[l] = s2[l];
	str[l] = 0;
	return (str - i);
}
