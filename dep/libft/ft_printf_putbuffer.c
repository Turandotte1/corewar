/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbuffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:03:54 by mrychkov          #+#    #+#             */
/*   Updated: 2017/11/05 19:04:00 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_putwbuff(t_printf *flags, wchar_t wc)
{
	if (wc < 0x7F)
		ft_putbuff(flags, (unsigned int)wc);
	else if (wc < 0x7FF)
	{
		ft_putbuff(flags, ((wc >> 6) + 0xC0));
		ft_putbuff(flags, (wc & 0x3F) + 0x80);
	}
	else if (wc < 0xFFFF)
	{
		ft_putbuff(flags, (((unsigned int)wc >> 12) + 0xE0));
		ft_putbuff(flags, ((((unsigned int)wc >> 6) & 0x3F) + 0x80));
		ft_putbuff(flags, ((unsigned int)wc & 0x3F) + 0x80);
	}
	else if (wc < 0x10FFFF)
	{
		ft_putbuff(flags, ((unsigned int)wc >> 18) + 0xF0);
		ft_putbuff(flags, (((unsigned int)wc >> 12) & 0x3F) + 0x80);
		ft_putbuff(flags, (((unsigned int)wc >> 6) & 0x3F) + 0x80);
		ft_putbuff(flags, ((unsigned int)wc & 0x3F) + 0x80);
	}
	return (0);
}

size_t				wstrlen_prec(wchar_t *ws, size_t prec, size_t len)
{
	if (*ws == '\0' || prec == 0)
		return (len);
	else if (*ws <= 0x7F)
		return (wstrlen_prec(ws + 1, prec - 1, len + 1));
	else if (*ws <= 0x7FF && prec >= 2)
		return (wstrlen_prec(ws + 1, prec - 2, len + 2));
	else if (*ws <= 0xFFFF && prec >= 3)
		return (wstrlen_prec(ws + 1, prec - 3, len + 3));
	else if (*ws <= 0x10FFFF && prec >= 4)
		return (wstrlen_prec(ws + 1, prec - 4, len + 4));
	else
		return (len);
}

int					ft_putwstrbuff(t_printf *flags, wchar_t *ws)
{
	size_t			len;

	len = flags->ret;
	while (*ws && len)
	{
		ft_putwbuff(flags, *ws);
		ws++;
		len--;
	}
	return (0);
}

int					ft_putstrbuff(t_printf *flags, char *str)
{
	size_t			i;
	size_t			len;

	i = 0;
	len = flags->ret + 1;
	while (*(str + i) && len)
	{
		ft_putbuff(flags, (*(str + i)));
		i++;
		len--;
	}
	if (flags->spec == 'd' || flags->spec == 'i')
		free(str);
	return (0);
}

int					ft_putbuff(t_printf *flags, char c)
{
	if (flags->buff_index + 1 < BUFF_SIZE)
		flags->buffer[flags->buff_index++] = c;
	else
	{
		if (write(1, flags->buffer, flags->buff_index + 1) == -1)
			flags->error = 1;
		flags->buff_index = 0;
	}
	return (0);
}
