/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtl_llccssierror.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:58:33 by mipham            #+#    #+#             */
/*   Updated: 2018/07/18 14:58:42 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_prtl.h"

int		prtl_ll(t_pm_env *e, int i)
{
	int		f;
	char	*str;

	f = (int)va_arg(*e->ap, int);
	str = ft_ldtoa(f);
	ft_putstr_fd("ligne :\033[33m\033[1m ", e->fd);
	ft_putstr_fd(str, e->fd);
	ft_putstr_fd("\n\033[0m", e->fd);
	free(str);
	return (++i);
}

int		prtl_cc(t_pm_env *e, int i)
{
	++i;
	if (e->s[i] == 'r')
		ft_putstr_fd("\033[31m\033[1m", e->fd);
	else if (e->s[i] == 'g')
		ft_putstr_fd("\033[32m\033[1m", e->fd);
	else if (e->s[i] == 'y')
		ft_putstr_fd("\033[33m\033[1m", e->fd);
	else if (e->s[i] == 'b')
		ft_putstr_fd("\033[34m\033[1m", e->fd);
	else if (e->s[i] == 'm')
		ft_putstr_fd("\033[35m\033[1m", e->fd);
	else if (e->s[i] == 'c')
		ft_putstr_fd("\033[36m\033[1m", e->fd);
	else if (e->s[i] == 'w')
		ft_putstr_fd("\033[37m\033[1m", e->fd);
	else if (e->s[i] == '0')
		ft_putstr_fd("\033[0m", e->fd);
	else
	{
		ft_putstr_fd("Format color incorrect\n", e->fd);
		return (-1);
	}
	return (++i);
}

int		prtl_ss(t_pm_env *e, int i)
{
	ft_putstr_fd("S : pas encore implémenté \n", e->fd);
	return (-1);
	if (i)
		return (-1);
}

int		prtl_error(t_pm_env *e, int i)
{
	ft_putstr_fd("Format Incorrect \n", e->fd);
	return (-1);
	if (i)
		return (-1);
}

int		prtl_i(t_pm_env *e, int i)
{
	ft_putstr_fd("\033[31m\033[1mError !!! \033[0m: ", e->fd);
	return (++i);
}
