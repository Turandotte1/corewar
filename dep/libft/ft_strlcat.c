/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:28:23 by mrychkov          #+#    #+#             */
/*   Updated: 2017/04/29 18:50:55 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (size - i > 0 && dest[i])
		i++;
	size -= i;
	while (size > 1 && src[j])
	{
		dest[i + j] = src[j];
		j++;
		size--;
	}
	if (j > 0)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
