/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:31:32 by mrychkov          #+#    #+#             */
/*   Updated: 2017/11/05 19:32:36 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				get_size(uintmax_t nb1, size_t base)
{
	int			size;

	size = 1;
	while (nb1 >= base)
	{
		size++;
		nb1 /= base;
	}
	return (size);
}

static int				get_size_neg(intmax_t nb)
{
	int size;

	size = 0;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char					*ft_itoa_unbase(uintmax_t nb1, size_t base)
{
	int			i;
	int			size;
	char		*output;
	char		itoa_base[16];

	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	ft_strncpy(itoa_base, "0123456789ABCDEF", base);
	size = get_size(nb1, base);
	if (!(output = malloc(sizeof(char) * size + 1)))
		return (NULL);
	output[size] = '\0';
	while (size - 1 >= i)
	{
		output[size - 1] = itoa_base[(nb1 % base)];
		size--;
		nb1 /= base;
	}
	return (output);
}

char					*ft_itoa_neg(intmax_t nb)
{
	char				*res;
	int					size;
	intmax_t			temp;

	temp = nb;
	if (nb <= 0)
		temp *= -1;
	size = get_size_neg(nb) - 1;
	if (!(res = malloc(sizeof(char) * size + 2)))
		return (NULL);
	res[size + 1] = '\0';
	if (nb == LLONG_MAX)
		res = ft_strcpy(res, "9223372036854775807");
	else if (nb == LLONG_MIN)
		res = ft_strcpy(res, "9223372036854775808");
	else
	{
		while (temp)
		{
			res[size--] = (temp % 10) + '0';
			temp /= 10;
		}
	}
	return (res);
}
