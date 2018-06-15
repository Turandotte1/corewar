/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:17:00 by mrychkov          #+#    #+#             */
/*   Updated: 2017/11/06 02:25:57 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t				check_size_signed(intmax_t num, t_printf *flags)
{
	if (flags->is_sizet)
		num = (size_t)num;
	else if (flags->is_long)
		num = (long)num;
	else if (flags->is_short)
		num = (short)num;
	else if (flags->is_shortshort)
		num = (char)num;
	else if (!flags->intmax && !flags->is_longlong)
		num = (int)num;
	return (num);
}

uintmax_t				check_size(long long unsigned int num, t_printf *flags)
{
	if (flags->intmax)
		num = (uintmax_t)num;
	else if (flags->is_sizet)
		num = (size_t)num;
	else if (flags->is_long)
		num = (unsigned long)num;
	else if (flags->is_short)
		num = (unsigned short)num;
	else if (flags->is_shortshort)
		num = (unsigned char)num;
	else if (!flags->is_longlong)
		num = (unsigned int)num;
	return (num);
}

int						print_zero(t_printf *flags)
{
	char				c;
	char				str[2];

	c = '0';
	flags->ret = 1;
	if (flags->prec && !flags->hash
			&& (flags->spec == 'o' || flags->spec == 'O'))
	{
		c = ' ';
	}
	else if (flags->width && (flags->spec == 'd' || flags->spec == 'D'))
	{
		if (flags->prec && flags->zero)
		{
			str[0] = '0';
			str[1] = '0';
			flags->zero = 0;
			flags->ret = 2;
			return (print_str(flags, str));
		}
		c = ((flags->zero || flags->left) ? '0' : ' ');
	}
	return (print_zero2(flags));
}

int						print_zero2(t_printf *flags)
{
	char				c;
	char				str[2];

	c = '0';
	if (flags->point && !flags->prec && !flags->width)
	{
		str[0] = ' ';
		str[1] = '\0';
		flags->ret = 0;
		return (print_str(flags, str));
	}
	else if (flags->point && (flags->spec != 'd' || flags->spec != 'D'))
		c = ' ';
	flags->hash = 0;
	return (print_char(flags, c));
}

int						str_nullprec(t_printf *flags)
{
	char				c;
	size_t				i;

	c = ' ';
	i = 0;
	if (flags->width)
	{
		while (i < flags->width)
		{
			ft_putbuff(flags, c);
			i++;
		}
	}
	return (0);
}
