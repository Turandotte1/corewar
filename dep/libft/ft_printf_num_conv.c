/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:22:44 by mrychkov          #+#    #+#             */
/*   Updated: 2017/10/30 18:05:28 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int							arg_d_i(t_printf *flags, va_list ap)
{
	intmax_t				num;
	char					*str;

	num = va_arg(ap, intmax_t);
	if (flags->spec == 'D')
		flags->is_long = 1;
	num = check_size_signed(num, flags);
	if (num < 0)
	{
		flags->minus = 1;
		flags->plus = 0;
	}
	else if (num == 0)
		return (print_zero(flags));
	str = ft_itoa_neg(num);
	flags->ret = ft_strlen(str);
	print_num(flags, str);
	return (0);
}

int							arg_o(t_printf *flags, va_list ap)
{
	unsigned long long int	num;
	char					*str;

	flags->plus = 0;
	flags->space = 0;
	num = va_arg(ap, unsigned long long int);
	if (flags->spec == 'O')
		flags->is_long = 1;
	if (num == 0)
		return (print_zero(flags));
	num = check_size(num, flags);
	str = ft_itoa_unbase(num, 8);
	if (flags->prec)
		flags->hash = 0;
	flags->ret = ft_strlen(str);
	if (flags->hash)
		flags->ret++;
	print_num(flags, str);
	free(str);
	return (0);
}

int							arg_u(t_printf *flags, va_list ap)
{
	unsigned long long int	num;
	char					*str;

	flags->plus = 0;
	flags->space = 0;
	num = va_arg(ap, unsigned long long int);
	if (flags->spec == 'U')
		flags->is_long = 1;
	num = check_size(num, flags);
	str = ft_itoa_unbase(num, 10);
	if (num == 0)
		return (print_zero(flags));
	flags->ret = ft_strlen(str);
	print_num(flags, str);
	free(str);
	return (0);
}

int							arg_x(t_printf *flags, va_list ap)
{
	unsigned long long int	num;
	char					*str;

	flags->plus = 0;
	flags->space = 0;
	num = va_arg(ap, unsigned long long int);
	num = check_size(num, flags);
	str = ft_itoa_unbase(num, 16);
	if (num == 0)
	{
		flags->hash = 0;
		return (print_zero(flags));
	}
	ft_tolower_str(str);
	flags->ret = ft_strlen(str);
	if (flags->hash)
		flags->ret += 2;
	print_num(flags, str);
	free(str);
	return (0);
}

int							arg_big_x(t_printf *flags, va_list ap)
{
	unsigned long long int	num;
	char					*str;

	flags->plus = 0;
	flags->space = 0;
	num = va_arg(ap, unsigned long long int);
	num = check_size(num, flags);
	str = ft_itoa_unbase(num, 16);
	if (num == 0)
	{
		flags->hash = 0;
		return (print_zero(flags));
	}
	flags->ret = ft_strlen(str);
	if (flags->hash)
		flags->ret += 2;
	print_num(flags, str);
	free(str);
	return (0);
}
