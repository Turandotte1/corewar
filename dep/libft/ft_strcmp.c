/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:43:26 by mrychkov          #+#    #+#             */
/*   Updated: 2017/04/29 18:46:09 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (*cs1 && *cs2 && *cs1 == *cs2)
	{
		cs1++;
		cs2++;
	}
	if (*cs1 != *cs2)
		return (*cs1 - *cs2);
	return (0);
}
