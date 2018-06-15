/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:14:44 by mrychkov          #+#    #+#             */
/*   Updated: 2017/10/24 13:18:58 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf		set_length(const char *format, t_printf *flags)
{
	if ((*(format + flags->index + 1) && *(format + flags->index) == 'j'))
	{
		flags->intmax = 1;
		flags->index++;
	}
	else if ((*(format + flags->index + 1) && *(format + flags->index) == 'z'))
	{
		flags->is_sizet = 1;
		flags->index++;
	}
	else if ((*(format + flags->index + 1) && *(format + flags->index) == 'h'))
	{
		flags->is_short = 1;
		flags->index++;
	}
	else if ((*(format + flags->index + 1) && *(format + flags->index) == 'l'))
	{
		flags->is_long = 1;
		flags->index++;
	}
	return (*flags);
}

t_printf		set_long_length(const char *format, t_printf *flags)
{
	if (*(format + flags->index) == 'h' && *(format + flags->index + 1) == 'h')
	{
		flags->is_shortshort = 1;
		flags->index += 2;
	}
	else if (*(format + flags->index) == 'l'
			&& *(format + flags->index + 1) == 'l')
	{
		flags->is_longlong = 1;
		flags->index += 2;
	}
	else
		set_length(format, flags);
	return (*flags);
}

t_printf		set_prec(const char *format, t_printf *flags)
{
	if (*(format + flags->index) == '.')
	{
		flags->index++;
		flags->point = 1;
		if (ft_isdigit(*(format + flags->index)))
		{
			flags->prec = ft_atoi(format + flags->index);
			while (ft_isdigit(*(format + flags->index)))
				flags->index++;
		}
	}
	return (*flags);
}

t_printf		set_width(const char *format, t_printf *flags)
{
	if (ft_isdigit(*(format + flags->index)))
	{
		flags->width = ft_atoi(format + flags->index);
		while (ft_isdigit(*(format + flags->index)))
			flags->index++;
	}
	return (*flags);
}

t_printf		set_flags(const char *format, t_printf *flags)
{
	while ((*(format + flags->index + 1)) && ((*(format + flags->index)) == ' '
	|| (*(format + flags->index)) == '#' || (*(format + flags->index)) == '0'
	|| (*(format + flags->index)) == '-' || (*(format + flags->index)) == '+'))
	{
		if ((*(format + flags->index)) == '#')
			flags->hash = 1;
		if ((*(format + flags->index)) == '-')
			flags->left = 1;
		if ((*(format + flags->index)) == ' ')
			flags->space = 1;
		if ((*(format + flags->index)) == '+')
			flags->plus = 1;
		if ((*(format + flags->index)) == '0')
			flags->zero = 1;
		flags->index++;
	}
	if (flags->plus && flags->space)
		flags->space = 0;
	if (flags->left && flags->zero)
		flags->zero = 0;
	return (*flags);
}
