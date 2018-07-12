//
// Created by Minh PHAM on 5/13/18.
//

#include "includes/ft_prtl.h"

/*
**	prtl_tt -> libft/prtl/prtl_t.c
**		print une tabulation
*/

int		prtl_tt(t_pm_env *e, int i)
{
	ft_putchar_fd('\t', e->fd);
	return (++i);
}

int		prtl_l(t_pm_env *e, int i)
{
	long int	f;
	char		*str;

	f = (long int)va_arg(*e->ap, long int);
	str = ft_ldtoa(f);
	write(e->fd, str, ft_strlen(str));
	free(str);
	return (++i);
}