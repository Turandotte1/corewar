/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:54:19 by mrychkov          #+#    #+#             */
/*   Updated: 2017/11/05 20:25:58 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						arg_s(t_printf *flags, va_list ap)
{
	char				*str;

	flags->space = 0;
	flags->plus = 0;
	if (flags->is_long == 1)
		return (arg_ws(flags, ap));
	if ((str = va_arg(ap, char *)) == NULL)
		return (str_null(flags));
	flags->ret = ft_strlen(str);
	if (flags->point && !flags->prec)
		return (str_nullprec(flags));
	if (flags->prec)
	{
		flags->ret = (flags->prec < ft_strlen(str) ?
				flags->prec : flags->ret);
	}
	return (print_str(flags, str));
}

int						arg_c(t_printf *flags, va_list ap)
{
	char				c;

	flags->space = 0;
	if (flags->is_long == 1)
		return (arg_wc(flags, ap));
	c = (char)va_arg(ap, int);
	if (c == 0)
		flags->plus = 0;
	flags->ret = 1;
	return (print_char(flags, c));
}

int						arg_ws(t_printf *flags, va_list ap)
{
	wchar_t				*ws;
	char				c;

	c = '0';
	flags->space = 0;
	if ((ws = va_arg(ap, wchar_t *)) == NULL)
	{
		flags->ret = 6;
		ft_putstrbuff(flags, "(null)");
		return (6);
	}
	flags->ret = ft_wstrlen(ws);
	if (flags->prec)
	{
		flags->ret = flags->prec ? wstrlen_prec(ws, flags->prec, 0)
				: ft_wstrlen(ws);
	}
	if (flags->zero && flags->width && flags->point && !flags->prec)
	{
		flags->ret = 1;
		return (print_char(flags, c));
	}
	return (print_wstr(flags, ws));
}

int						arg_wc(t_printf *flags, va_list ap)
{
	wchar_t				wc;

	flags->space = 0;
	wc = va_arg(ap, wchar_t);
	flags->ret = ft_wclen(wc);
	return (print_wchar(flags, wc));
}

int						str_null(t_printf *flags)
{
	char				c;

	c = '0';
	if (flags->zero)
	{
		flags->ret = 1;
		return (print_char(flags, c));
	}
	else
	{
		flags->ret = 6;
		ft_putstrbuff(flags, "(null)");
		return (6);
	}
}
