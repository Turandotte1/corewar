/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:30:28 by mipham            #+#    #+#             */
/*   Updated: 2017/11/13 14:34:18 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		if (!n)
			return (1);
		while ((s1[i] == s2[i]) && s1[i] && s2[i] && n - 1)
		{
			i++;
			n--;
		}
		if (s1[i] == s2[i])
			return (1);
		return (0);
	}
	return (0);
}
