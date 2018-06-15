/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:15:48 by mrychkov          #+#    #+#             */
/*   Updated: 2017/11/05 19:16:52 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						arg_p(t_printf *flags, va_list ap)
{
	uintmax_t			num;
	char				*str;
	char				c;

	c = 0;
	flags->hash = 1;
	flags->plus = 0;
	flags->space = 0;
	num = (uintmax_t)va_arg(ap, void *);
	str = ft_itoa_unbase(num, 16);
	ft_tolower_str(str);
	if (num == 0 && flags->point && !flags->prec)
		return (print_zero(flags));
	flags->ret = ft_strlen(str) + 2;
	print_num(flags, str);
	free(str);
	return (0);
}

int						print_perc(t_printf *flags, va_list ap)
{
	(void)ap;
	flags->ret = 1;
	if (flags->left && flags->width)
	{
		ft_putbuff(flags, '%');
		width_print(flags);
		return (flags->ret);
	}
	else if (flags->width)
		width_print(flags);
	ft_putbuff(flags, '%');
	return (flags->ret);
}
