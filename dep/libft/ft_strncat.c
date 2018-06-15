/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:51:05 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 16:44:36 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	int		size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i] && i < nb)
	{
		dest[i + size] = src[i];
		i++;
	}
	dest[i + size] = '\0';
	return (dest);
}
