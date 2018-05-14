/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:38:30 by mipham            #+#    #+#             */
/*   Updated: 2017/11/15 14:49:15 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_verif(int nbr)
{
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}

static char		*ft_itoa_core(int nbr, int puissance, int signe)
{
	int		r;
	int		value;
	char	*res;

	r = 0;
	value = nbr;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		puissance++;
	}
	if (!(res = (char*)malloc(sizeof(char) * (puissance + 1))))
		return (NULL);
	res[puissance] = '\0';
	while (puissance >= signe)
	{
		r = value % 10;
		value = value / 10;
		res[puissance--] = r + 48;
	}
	if (signe == 1)
		res[0] = '-';
	return (res);
}

char			*ft_itoa(int nbr)
{
	int		puissance;

	puissance = 0;
	if (nbr == 0 || nbr == -2147483648)
		return (ft_verif(nbr));
	if (nbr < 0)
		return (ft_itoa_core(-nbr, ++puissance, 1));
	else
		return (ft_itoa_core(nbr, puissance, 0));
}

static void	ft_comp_ldtoa(long int nb, char l, char *str)
{
	if (nb == LLONG_MIN)
	{
		str[l - 1] = '8';
		ft_comp_ldtoa(nb / 10, l - 1, str);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			str[0] = '-';
		}
		if (nb > 9)
			ft_comp_ldtoa(nb / 10, l - 1, str);
		str[l - 1] = (nb % 10) + '0';
	}
}

/*
**	ft_ldtoa	-> libft/string/ft_itoa2.c
**		convertie un long int en string
*/

char		*ft_ldtoa(long int n)
{
	char		l;
	char		*str;
	long int	nb;

	nb = n;
	l = (n < 0) ? 2 : 1;
	while (n /= 10)
		++l;
	if (!(str = ft_strnew(l)))
		return (NULL);
	ft_comp_ldtoa(nb, l, str);
	return (str);
}
