/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:19:36 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/09 05:23:34 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_funct_ptr		g_function_table[NB_ARGS] =
{
	{'s', &arg_s},
	{'S', &arg_ws},
	{'c', &arg_c},
	{'C', &arg_wc},
	{'d', &arg_d_i},
	{'i', &arg_d_i},
	{'D', &arg_d_i},
	{'o', &arg_o},
	{'O', &arg_o},
	{'u', &arg_u},
	{'U', &arg_u},
	{'x', &arg_x},
	{'X', &arg_big_x},
	{'p', &arg_p},
	{'%', &print_perc},
};

int				error_managment(const char *format, t_printf *flags)
{
	if (flags->error == 1)
	{
		if (flags->left)
		{
			ft_putbuff(flags, (*(format + flags->index)));
			if (flags->width)
			{
				flags->ret = flags->buff_index - 1;
				width_print(flags);
			}
		}
		else
		{
			if (flags->width)
			{
				flags->ret = flags->buff_index;
				width_print(flags);
			}
			ft_putbuff(flags, (*(format + flags->index)));
		}
		flags->error = 0;
	}
	return (0);
}

int				set_args(const char *format, t_printf *flags, va_list ap)
{
	int i;

	i = 0;
	if (!(*(format + flags->index)))
		return (0);
	flags->spec = *(format + flags->index);
	while (i < NB_ARGS)
	{
		if (flags->spec == g_function_table[i].flag)
			return (g_function_table[i].ptr(flags, ap));
		i++;
	}
	flags->error = 1;
	error_managment(format, flags);
	return (flags->buff_index);
}

int				start_parsing(const char *format, t_printf *flags, va_list ap)
{
	size_t i;

	i = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%' && (*(format + i + 1)))
		{
			flags->index = ++i;
			set_flags(format, flags);
			set_width(format, flags);
			set_prec(format, flags);
			set_long_length(format, flags);
			set_args(format, flags, ap);
			i = flags->index;
		}
		else if (*(format + i) == '%')
			return (flags->buff_index);
		else
			ft_putbuff(flags, (*(format + i)));
		i++;
	}
	return (flags->buff_index);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	t_printf	*flags;
	va_list		ap;

	if (!(flags = malloc(sizeof(t_printf))))
		return (-1);
	flags = init_flags(flags);
	va_start(ap, format);
	start_parsing(format, flags, ap);
	if (write(1, flags->buffer, flags->buff_index) == -1)
		flags->buff_index = -1;
	va_end(ap);
	ret = flags->buff_index;
	free(flags);
	return (ret);
}
