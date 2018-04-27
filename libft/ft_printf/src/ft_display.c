/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:14:06 by mipham            #+#    #+#             */
/*   Updated: 2017/12/18 18:01:09 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	ssize_t	handle_arg(char **format, va_list *args, t_arg *sarg)
{
	ssize_t		ret;
	t_handler	handler;

	if ((*(++*format)) == '\0')
		return (0);
	if ((ft_parse_flags(format, sarg)) == NULL)
		return (-1);
	if ((ft_parse_width(format, args, sarg)) == NULL)
		return (-1);
	if ((ft_parse_precision(format, args, sarg)) == NULL)
		return (-1);
	if ((ft_parse_length(format, sarg)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (ft_get_handler(**format) == NULL)
		handler = ft_handle_null;
	else
		handler = ft_get_handler(**format);
	ret = handler(format, args, sarg);
	(*format)++;
	return (ret);
}

int				ft_inner_printf(const char *format, va_list *args, size_t chrs)
{
	char	*next_arg;
	t_arg	sarg;
	ssize_t	handler_len;

	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (chrs);
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (chrs + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (ft_inner_printf(next_arg, args, chrs + (next_arg - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg));
		if ((handler_len = handle_arg((char**)&format, args, &sarg)) == -1)
			return (-1);
		else
			return (ft_inner_printf(format, args, chrs + handler_len));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_inner_printf(format, &args, 0);
	va_end(args);
	return (ret);
}
