
#include "includes/libft.h"

static void		ft_comp_lutoa(size_t nb, char l, char *str)
{
	if (nb > 9)
		ft_comp_lutoa(nb / 10, l - 1, str);
	str[l - 1] = (nb % 10) + '0';
}

/*
**	ft_lutoa	-> libft/string/ft_itoa2.c
**		convertie un unsigned long int en string
*/

char			*ft_lutoa(size_t n)
{
	char		l;
	char		*str;
	long int	nb;

	nb = n;
	l = 1;
	while (n /= 10)
		++l;
	if (!(str = ft_strnew(l)))
		return (NULL);
	ft_comp_lutoa(nb, l, str);
	return (str);
}
