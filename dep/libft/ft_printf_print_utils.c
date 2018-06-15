/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:13:41 by mrychkov          #+#    #+#             */
/*   Updated: 2017/10/30 18:16:42 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						width_prec_print(t_printf *flags, char *str)
{
	size_t i;

	i = 0;
	flags->space = 0;
	if (flags->plus || flags->minus)
		i++;
	if (flags->prec < flags->ret)
	{
		while (i++ < (flags->width - flags->ret))
			ft_putbuff(flags, ' ');
		i--;
	}
	else
	{
		while (i++ < (flags->width - flags->prec))
			ft_putbuff(flags, ' ');
		i--;
	}
	flags->ret += i;
	prec_print(flags, str);
	return (flags->ret);
}

int						width_print(t_printf *flags)
{
	size_t i;

	i = 0;
	if (flags->zero)
		suffix_print(flags);
	if (flags->plus || flags->minus)
		i++;
	if (flags->ret < flags->width)
	{
		while (i++ < (flags->width - flags->ret))
			flags->zero ? ft_putbuff(flags, '0') : ft_putbuff(flags, ' ');
	}
	return (flags->ret);
}

int						prec_print(t_printf *flags, char *str)
{
	size_t i;

	i = 0;
	suffix_print(flags);
	if (ft_strlen(str) < flags->prec)
	{
		while (i++ < (flags->prec - ft_strlen(str)))
			ft_putbuff(flags, '0');
		i--;
	}
	flags->ret += i;
	return (flags->ret);
}

void					suffix_print(t_printf *flags)
{
	sign_print(flags);
	if (flags->hash && (flags->spec == 'x' || flags->spec == 'p'))
	{
		ft_putbuff(flags, '0');
		ft_putbuff(flags, 'x');
		flags->hash = 0;
	}
	if (flags->hash && (flags->spec == 'X'))
	{
		ft_putbuff(flags, '0');
		ft_putbuff(flags, 'X');
		flags->hash = 0;
	}
	if (flags->hash && (flags->spec == 'o' || flags->spec == 'O'))
	{
		ft_putbuff(flags, '0');
		flags->hash = 0;
	}
}

void					sign_print(t_printf *flags)
{
	if (flags->plus)
	{
		ft_putbuff(flags, '+');
		flags->plus = 0;
		flags->ret++;
	}
	if (flags->space && !flags->minus)
	{
		ft_putbuff(flags, ' ');
		flags->space = 0;
		flags->ret++;
	}
	if (flags->minus)
	{
		ft_putbuff(flags, '-');
		flags->minus = 0;
		flags->ret++;
	}
}
