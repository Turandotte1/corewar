/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:11:09 by mrychkov          #+#    #+#             */
/*   Updated: 2017/04/29 19:36:11 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest;
	char *csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	while (n--)
		*cdest++ = *csrc++;
	return (dest);
}
