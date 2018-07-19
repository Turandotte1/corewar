/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:35:08 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 16:18:33 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	int i;

	i = -1;
	if (s && f)
	{
		while (s[++i])
			f(&s[i]);
	}
}
