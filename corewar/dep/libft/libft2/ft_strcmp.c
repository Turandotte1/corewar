/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:20:57 by mipham            #+#    #+#             */
/*   Updated: 2018/07/14 16:51:15 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** ^ le ou exclusif binaire, qui renvoie 1 que si un seul des deux est vrai
** 1 ^ 1 = 0 , 0 ^ 0 = 0, 1 ^ 0 = 1
** 0 ^ 1 = 1
** (s1 && s2) || (!s1 && !s2)
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (!(s1[i] ^ s2[i]))
	{
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	return (s1[i] - s2[i]);
}
