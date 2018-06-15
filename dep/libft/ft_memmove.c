/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:57:11 by mrychkov          #+#    #+#             */
/*   Updated: 2017/04/29 18:36:57 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *new;

	new = ft_strnew(len);
	if (new)
	{
		src = ft_memcpy(new, src, len);
		dst = ft_memcpy(dst, new, len);
	}
	return (dst);
}
