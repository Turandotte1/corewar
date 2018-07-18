/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtl_tl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:59:00 by mipham            #+#    #+#             */
/*   Updated: 2018/07/18 15:00:21 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
