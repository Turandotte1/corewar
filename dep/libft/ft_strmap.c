/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 20:25:18 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 16:45:56 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*ptr;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(ptr = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (f != NULL && s[i])
	{
		ptr[i] = f(s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
