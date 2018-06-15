/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:59 by mrychkov          #+#    #+#             */
/*   Updated: 2017/04/29 18:41:12 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen((char*)s1);
	while (s2[i])
	{
		s1[i + size] = s2[i];
		i++;
	}
	s1[i + size] = '\0';
	return (s1);
}
