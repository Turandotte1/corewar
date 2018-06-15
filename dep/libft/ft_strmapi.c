/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 20:27:19 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 16:46:33 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*ptr;

	if (!s && !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(ptr = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (f != NULL && s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
