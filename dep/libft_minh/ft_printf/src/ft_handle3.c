/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:16:11 by mipham            #+#    #+#             */
/*   Updated: 2017/12/19 13:16:15 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_handle_wchar(char **format, va_list *args, t_arg *arg)
{
	wchar_t		chr;
	int			chr_len;

	(void)format;
	chr = (wchar_t)va_arg(*args, wchar_t);
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->get_width && !arg->right_pad)
		ft_width_pad(chr_len, arg->width, arg->pad_zero ? '0' : ' ');
	ft_putwchar(chr);
	if (arg->get_width && arg->right_pad)
		ft_width_pad(chr_len, arg->width, arg->pad_zero ? '0' : ' ');
	return (arg->get_width ? ft_max(chr_len, arg->width) : chr_len);
}

ssize_t	calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

ssize_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t	ft_handle_wstr(char **format, va_list *args, t_arg *arg)
{
	wchar_t	*str;
	ssize_t	strlen;

	(void)format;
	(void)arg;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = arg->get_prec ? calc_wstrlen(str, arg->precision, 0) :
	ft_wstrlen(str);
	if (arg->get_width && !arg->right_pad)
		ft_width_pad(strlen, arg->width, (arg->pad_zero ? '0' : ' '));
	ft_putnwstr(str, (size_t)strlen);
	if (arg->get_width && arg->right_pad)
		ft_width_pad((size_t)strlen, arg->width, ' ');
	return (arg->get_width ? ft_max((int)strlen, arg->width) : strlen);
}
