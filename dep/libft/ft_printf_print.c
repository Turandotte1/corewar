/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:44:17 by mrychkov          #+#    #+#             */
/*   Updated: 2017/10/30 18:13:24 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				print_str(t_printf *flags, char *str)
{
	size_t		i;

	i = 0;
	if (flags->left && flags->width && flags->ret < flags->width)
	{
		while (i < flags->ret)
			ft_putbuff(flags, str[i++]);
		width_print(flags);
		return (flags->ret);
	}
	else if (flags->width && flags->ret < flags->width)
		width_print(flags);
	suffix_print(flags);
	while (i < flags->ret)
		ft_putbuff(flags, str[i++]);
	return (flags->ret);
}

int				print_char(t_printf *flags, char c)
{
	if (flags->left && flags->width && flags->ret < flags->width)
	{
		suffix_print(flags);
		ft_putbuff(flags, c);
		width_print(flags);
		return (flags->ret);
	}
	else if (flags->width && flags->ret < flags->width)
		width_print(flags);
	suffix_print(flags);
	ft_putbuff(flags, c);
	return (flags->ret);
}

int				print_wstr(t_printf *flags, wchar_t *ws)
{
	if (flags->left)
	{
		ft_putwstrbuff(flags, ws);
		if (flags->width)
			width_print(flags);
	}
	else
	{
		if (flags->width)
			width_print(flags);
		ft_putwstrbuff(flags, ws);
	}
	return (flags->ret);
}

int				print_wchar(t_printf *flags, wchar_t wc)
{
	if (flags->left)
	{
		if (flags->width)
		{
			ft_putwbuff(flags, wc);
			width_print(flags);
		}
		else
			ft_putwbuff(flags, wc);
	}
	else
	{
		if (flags->width)
		{
			width_print(flags);
			ft_putwbuff(flags, wc);
		}
		else
			ft_putwbuff(flags, wc);
	}
	return (flags->ret);
}

int				print_num(t_printf *flags, char *str)
{
	if (flags->left)
	{
		if (flags->prec && ft_strlen(str) < flags->prec)
			prec_print(flags, str);
		else
			suffix_print(flags);
		ft_putstrbuff(flags, str);
		if (flags->width && (flags->ret < flags->width))
			width_print(flags);
	}
	else
	{
		if (flags->prec && flags->width && flags->prec < flags->width
				&& ft_strlen(str) <= flags->width - flags->prec)
			width_prec_print(flags, str);
		else if (flags->prec && ft_strlen(str) < flags->prec)
			prec_print(flags, str);
		else if (flags->width && flags->ret < flags->width)
			width_print(flags);
		suffix_print(flags);
		ft_putstrbuff(flags, str);
	}
	return (flags->ret);
}
