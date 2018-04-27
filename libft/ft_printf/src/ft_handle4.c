/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:16:22 by mipham            #+#    #+#             */
/*   Updated: 2017/12/19 14:35:26 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t		ft_handle_null(char **format, va_list *args, t_arg *arg)
{
	(void)args;
	if (arg->get_width && !arg->right_pad)
		ft_width_pad(1, arg->width, (char)(arg->pad_zero ? '0' : ' '));
	ft_putchar(**format);
	if (arg->get_width && arg->right_pad)
		ft_width_pad(1, arg->width, ' ');
	return (arg->get_width ? ft_max(arg->width, 1) : 1);
}

intmax_t	ft_get_signed_from_length(va_list *args, t_arg *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->length == hh)
		nbr = (char)nbr;
	else if (arg->length == h)
		nbr = (short int)nbr;
	else if (arg->length == l)
		nbr = (long int)nbr;
	else if (arg->length == ll)
		nbr = (long long int)nbr;
	else if (arg->length == j)
		nbr = (intmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	ft_get_unsigned_from_length(va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, uintmax_t);
	if (arg->length == hh)
		nbr = (unsigned char)nbr;
	else if (arg->length == h)
		nbr = (unsigned short int)nbr;
	else if (arg->length == l)
		nbr = (unsigned long int)nbr;
	else if (arg->length == ll)
		nbr = (unsigned long long int)nbr;
	else if (arg->length == j)
		nbr = (uintmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
