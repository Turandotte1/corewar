/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 21:23:34 by mrychkov          #+#    #+#             */
/*   Updated: 2017/10/31 21:23:51 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_wstrlen(wchar_t *ws)
{
	size_t len;
	size_t i;

	len = 0;
	i = 0;
	while (*(ws + i))
	{
		if (*ws <= 0x7F)
			len++;
		else if (*ws <= 0x7FF)
			len += 2;
		else if (*ws <= 0xFFFF)
			len += 3;
		else if (*ws <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}
