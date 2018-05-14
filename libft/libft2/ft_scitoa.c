
#include "includes/libft.h"

/*
**	ft_cmpt_put ->	libft/string/ft_scitoa.c
**		ecrit le nombre de puissance de 10
*/

static char		ft_cmpt_put(char *s, short cmpt)
{
	int i;

	if (cmpt > 9)
		i = ft_cmpt_put(s, cmpt / 10);
	else
		i = 0;
	s[i] = cmpt % 10 + '0';
	return (i + 1);
}

/*
**	ft_scitoa2 ->	libft/string/ft_scitoa.c
**		suite de l'algorithme de conversion
**		ecriture de la partie decimale
*/

static int		ft_scitoa2(double nb, int i, char pre, char *res)
{
	char tmp;

	tmp = (char)nb;
	res[i] = tmp + '0';
	nb = (nb - (double)tmp) * 10.0;
	if (pre > 0)
		res[++i] = '.';
	while (pre)
	{
		tmp = (char)nb;
		res[++i] = tmp + '0';
		nb = (nb - (double)tmp) * 10.0;
		--pre;
		if (nb == 0.0)
			break ;
	}
	res[i] = 'E';
	return (++i);
}

/*
**	ft_scitoa_cmpt ->	libft/string/ft_scitoa.c
**		determine le nombre de puissance de 10
*/

short			ft_scitoa_cmpt(double *nb)
{
	short cmpt;

	if (*nb == 0)
		return (0);
	cmpt = 0;
	while (*nb >= 10.0)
	{
		*nb /= 10.0;
		++cmpt;
	}
	while (*nb < 1.0)
	{
		*nb *= 10.0;
		--cmpt;
	}
	return (cmpt);
}

/*
**	ft_scitoa	->	libft/string/ft_scitoa.c
**		convertie un float/double en string
**		avec notation scientifique
**
**	ft_memalloc	--> libft/ft_memalloc.c
**		allou avec malloc une zonne memoire et la set a 0
**	ft_scitoa_cmpt ->	libft/string/ft_scitoa.c
**		determine le nombre de puissance de 10
**	ft_scitoa2 ->	libft/string/ft_scitoa.c
**		suite de l'algorithme de conversion
**		ecriture de la partie decimale
**	ft_cmpt_put ->	libft/string/ft_scitoa.c
**		ecrit le nombre de puissance de 10
*/

char			*ft_scitoa(double nb, char pre)
{
	char	*res;
	int		i;
	short	cmpt;

	if (pre < 0 || pre > 100)
		return (NULL);
	if (!(res = (char*)ft_memalloc(pre + 10)))
		return (NULL);
	i = 0;
	if (nb < 0.0)
	{
		nb = -nb;
		res[i++] = '-';
	}
	cmpt = ft_scitoa_cmpt(&nb);
	i = ft_scitoa2(nb, i, pre, res);
	if (cmpt >= 0)
		res[i] = '+';
	else
	{
		res[i] = '-';
		cmpt = -cmpt;
	}
	ft_cmpt_put(res + i + 1, cmpt);
	return (res);
}
