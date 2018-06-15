/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 20:40:59 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 16:47:25 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		k;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (j + k + 1))))
		return (NULL);
	j = -1;
	k = -1;
	while (s1[++j])
		ptr[j] = ((char *)s1)[j];
	while (s2[++k])
		ptr[j++] = ((char *)s2)[k];
	ptr[j] = '\0';
	return (ptr);
}
