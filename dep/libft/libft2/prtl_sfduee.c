//
// Created by Minh PHAM on 5/13/18.
//

#include "includes/ft_prtl.h"

int		prtl_s(t_pm_env *e, int i)
{
	char *str;

	str = (char*)va_arg(*e->ap, char*);
	write(e->fd, str, ft_strlen(str));
	return (++i);
}

int		prtl_f(t_pm_env *e, int i)
{
	double	f;
	char	*str;

	f = (double)va_arg(*e->ap, double);
	str = ft_scitoa(f, 6);
	write(e->fd, str, ft_strlen(str));
	free(str);
	return (++i);
}

int		prtl_d(t_pm_env *e, int i)
{
	int		f;
	char	*str;

	f = (int)va_arg(*e->ap, int);
	str = ft_itoa(f);
	write(e->fd, str, ft_strlen(str));
	free(str);
	return (++i);
}

int		prtl_u(t_pm_env *e, int i)
{
	size_t	f;
	char	*str;

	f = (size_t)va_arg(*e->ap, size_t);
	str = ft_lutoa(f);
	write(e->fd, str, ft_strlen(str));
	free(str);
	return (++i);
}

int		prtl_ee(t_pm_env *e, int i)
{
	int		f;
	char	*str;

	f = (int)va_arg(*e->ap, int);
	str = strerror(f);
	ft_putendl_fd(str, e->fd);
	return (++i);
}
