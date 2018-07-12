/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:15:54 by mipham            #+#    #+#             */
/*   Updated: 2017/12/19 15:33:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_handle_char(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	if (arg->length == l)
		return (ft_handle_wchar(format, args, arg));
	else
	{
		if (arg->get_width && !arg->right_pad)
			ft_width_pad(1, arg->width, arg->pad_zero ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->get_width && arg->right_pad)
			ft_width_pad(1, arg->width, ' ');
		return (arg->get_width ? ft_max(arg->width, 1) : 1);
	}
}

ssize_t	ft_handle_charswritten(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	return (0);
}

ssize_t	ft_handle_ptr(char **format, va_list *args, t_arg *arg)
{
	char		*base;
	uintmax_t	nbr;

	(void)format;
	arg->length = z;
	if (arg->get_prec)
		arg->pad_zero = 0;
	base = "0123456789abcdef";
	nbr = ft_get_unsigned_from_length(args, arg);
	return (ft_nbrforceprefix(nbr, base, arg, "0x"));
}

ssize_t	ft_handle_str(char **format, va_list *args, t_arg *arg)
{
	char	*str;
	ssize_t	strlen;

	if (arg->length == l)
		return (ft_handle_wstr(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(null)";
		strlen = arg->get_prec ? ft_nstrlen(str, arg->precision) :
			ft_strlen(str);
		if (arg->get_width && !arg->right_pad)
			ft_width_pad(strlen, arg->width, arg->pad_zero ?
					'0' : ' ');
		ft_putnstr(str, strlen);
		if (arg->get_width && arg->right_pad)
			ft_width_pad(strlen, arg->width, ' ');
		return (arg->get_width ? ft_max(strlen, arg->width) : strlen);
	}
}

ssize_t	ft_handle_escape(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	if (arg->get_width && !arg->right_pad)
		ft_width_pad(1, arg->width, arg->pad_zero ? '0' : ' ');
	ft_putchar('%');
	if (arg->get_width && arg->right_pad)
		ft_width_pad(1, arg->width, ' ');
	return (arg->get_width ? ft_max(arg->width, 1) : 1);
}
