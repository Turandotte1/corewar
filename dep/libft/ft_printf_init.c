/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:56:29 by mrychkov          #+#    #+#             */
/*   Updated: 2017/11/05 18:56:45 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf		*init_flags(t_printf *flags)
{
	flags->hash = 0;
	flags->left = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = 0;
	flags->is_shortshort = 0;
	flags->is_longlong = 0;
	flags->intmax = 0;
	flags->is_sizet = 0;
	flags->is_short = 0;
	flags->is_long = 0;
	flags->spec = '\0';
	flags->index = 0;
	flags->ret = 0;
	flags->count = 0;
	flags->point = 0;
	flags->error = '\0';
	flags->buff_index = 0;
	return (flags);
}
