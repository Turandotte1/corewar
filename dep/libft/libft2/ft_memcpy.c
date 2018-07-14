/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:04:44 by mipham            #+#    #+#             */
/*   Updated: 2018/07/14 16:48:01 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memcpy(void *restrict str1, const void *restrict str2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = str1;
	src = str2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (str1);
}

void		*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	while (i <= n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[n - i];
		++i;
	}
	return (dst);
}
