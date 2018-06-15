/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:58:46 by mrychkov          #+#    #+#             */
/*   Updated: 2017/04/29 19:00:20 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	if (ft_strlen(s1) == 0 || len == 0)
		return (NULL);
	len = len - 1;
	while (s1[i] && (i <= len))
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if ((i + j == len + 1) && (j + 1 != '\0'))
				return (NULL);
			j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		i++;
	}
	return (0);
}
