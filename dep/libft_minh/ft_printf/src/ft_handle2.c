/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:15:26 by mipham            #+#    #+#             */
/*   Updated: 2017/12/19 13:28:30 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_handle_binary(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_get_unsigned_from_length(args, arg);
	return (ft_handle_uint(nbr, arg, "01", "0b"));
}

ssize_t	ft_handle_hex(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = ft_get_unsigned_from_length(args, arg);
	if (arg->pad_zero && arg->force_prefix)
		arg->width -= 2;
	if (**format == 'X')
		return (ft_handle_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (ft_handle_uint(nbr, arg, "0123456789abcdef", "0x"));
}

ssize_t	ft_handle_long(char **format, va_list *args, t_arg *arg)
{
	arg->length = l;
	return (ft_get_handler(ft_tolower(**format))(format, args, arg));
}

ssize_t	ft_handle_int(char **format, va_list *args, t_arg *arg)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	if (arg->get_prec)
		arg->pad_zero = 0;
	nbr = ft_get_signed_from_length(args, arg);
	if (nbr < 0 || arg->force_sign || arg->blank_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (arg->force_sign)
			prefix = "+";
		else if (arg->blank_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_nbrforceprefix((uintmax_t)nbr, "0123456789", arg, prefix));
	}
	else
		return (ft_handle_uint((uintmax_t)nbr, arg, "0123456789", NULL));
}

ssize_t	ft_handle_octal(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_get_unsigned_from_length(args, arg);
	if (arg->force_prefix && nbr == 0 &&
			arg->get_prec && arg->precision == 0)
	{
		if (arg->get_width && !arg->right_pad)
			ft_width_pad(1, arg->width, (char)(arg->pad_zero ? '0' : ' '));
		ft_putstr("0");
		if (arg->get_width && arg->right_pad)
			ft_width_pad(1, arg->width, ' ');
		return (arg->get_width ? ft_max(arg->width, 1) : 1);
	}
	else if (arg->force_prefix && nbr != 0)
	{
		arg->get_prec = 1;
		arg->precision = (unsigned int)ft_max(arg->precision,
						ft_nbrlen(nbr, "01234567") + 1);
	}
	return (ft_handle_uint(nbr, arg, "01234567", NULL));
}
