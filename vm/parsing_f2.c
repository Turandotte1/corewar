/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:12:30 by glegendr          #+#    #+#             */
/*   Updated: 2018/06/20 18:12:31 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

int					f_live(t_act *act, t_vec *vec, int i)
{
	int			y;

	y = 0;
	act->f_p = 0;
	while (y++ < 3 && i < v_size(vec))
	{
		act->f_p += *(int *)v_get(vec, i);
		act->f_p <<= 8;
		++i;
	}
	act->s_p += *(int *)v_get(vec, i);
	return (i + 1);
}

int					f_ld(t_act *act, t_vec *vec, int i)
{
	int			id;

	id = *(int *)v_get(vec, i++);
	if (id == 0xd0)
	{
		act->f_p = *(int *)v_get(vec, i);
		act->f_p <<= 8;
		++i;
		act->f_p += *(int *)v_get(vec, i++);
	}
	else if (id == 0x90)
		i = f_live(act, vec, i++);
	else
		error("Bad Action");
	act->s_p = *(int *)v_get(vec, i);
	return (i + 1);
}
