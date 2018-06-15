/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:16:45 by mipham            #+#    #+#             */
/*   Updated: 2017/12/19 14:36:11 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		setup_arr(t_handler *handlers)
{
	handlers['%'] = &ft_handle_escape;
	handlers['s'] = &ft_handle_str;
	handlers['S'] = &ft_handle_wstr;
	handlers['p'] = &ft_handle_ptr;
	handlers['d'] = &ft_handle_int;
	handlers['D'] = &ft_handle_long;
	handlers['i'] = &ft_handle_int;
	handlers['o'] = &ft_handle_octal;
	handlers['O'] = &ft_handle_long;
	handlers['u'] = &ft_handle_unsigned;
	handlers['U'] = &ft_handle_long;
	handlers['x'] = &ft_handle_hex;
	handlers['X'] = &ft_handle_hex;
	handlers['c'] = &ft_handle_char;
	handlers['C'] = &ft_handle_wchar;
	handlers['b'] = &ft_handle_binary;
	handlers['n'] = &ft_handle_charswritten;
}

t_handler	ft_get_handler(char c)
{
	static t_handler	*handlers = NULL;

	if (handlers == NULL)
	{
		handlers = ft_memalloc(sizeof(*handlers) * 256);
		if (handlers != NULL)
			setup_arr(handlers);
	}
	return (handlers[(int)c]);
}

void		ft_putnbrbp(uintmax_t nbr, char *base, t_arg *arg, unsigned nbr_len)
{
	if (arg->get_prec)
		ft_width_pad(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->get_prec && arg->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}

ssize_t		ft_handle_uint(uintmax_t nbr,
		t_arg *arg, char *base, char *prefix)
{
	unsigned int			nbr_len;
	unsigned int			nbrstrlen;

	if (arg->get_prec)
		arg->pad_zero = 0;
	nbr_len = ft_nbrlen(nbr, base);
	if (arg->get_width && !arg->right_pad && arg->pad_zero)
	{
		if (arg->get_prec)
			arg->precision = ft_max(arg->width, arg->precision);
		else
			arg->precision = ft_max(arg->width, nbr_len);
		arg->get_prec = 1;
		arg->get_width = 0;
	}
	nbrstrlen = ft_calc_nbrstrlen(nbr, base, prefix, arg);
	if (arg->get_width && !arg->right_pad)
		ft_width_pad(nbrstrlen, arg->width, ' ');
	if (arg->force_prefix && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbrbp(nbr, base, arg, nbr_len);
	if (arg->get_width && arg->right_pad)
		ft_width_pad(nbrstrlen, arg->width, ' ');
	return (arg->get_width ? (ssize_t)ft_max(nbrstrlen, arg->width) :
			(ssize_t)nbrstrlen);
}
