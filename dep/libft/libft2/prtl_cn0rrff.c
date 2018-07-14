#include "includes/ft_prtl.h"

int		prtl_c(t_pm_env *e, int i)
{
	char	f;

	f = (char)va_arg(*e->ap, int);
	write(e->fd, &f, 1);
	return (++i);
}

int		prtl_n(t_pm_env *e, int i)
{
	ft_putchar_fd('\n', e->fd);
	return (++i);
}

int		prtl_0(t_pm_env *e, int i)
{
	exit(0);
	if (e)
		ft_putchar_fd('\n', e->fd);
	return (++i);
}

int		prtl_rr(t_pm_env *e, int i)
{
	char *str;

	str = (char*)va_arg(*e->ap, char*);
	ft_putstr_fd("file :\033[33m\033[1m ", e->fd);
	ft_putstr_fd(str, e->fd);
	ft_putstr_fd("\n\033[0m", e->fd);
	return (++i);
}

int		prtl_ff(t_pm_env *e, int i)
{
	char *str;

	str = (char*)va_arg(*e->ap, char*);
	ft_putstr_fd("function :\033[33m\033[1m ", e->fd);
	ft_putstr_fd(str, e->fd);
	ft_putstr_fd("\n\033[0m", e->fd);
	return (++i);
}
