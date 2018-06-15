/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:59:17 by mrychkov          #+#    #+#             */
/*   Updated: 2018/02/16 19:59:40 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atoi_max(const char *str)
{
	intmax_t	res;
	size_t		i;
	int			neg;

	res = 0;
	i = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		neg = (str[i] == 45 ? -1 : 1);
		i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - 48;
	return (res * neg);
}
