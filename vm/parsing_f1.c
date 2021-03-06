/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_f1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:12:27 by glegendr          #+#    #+#             */
/*   Updated: 2018/06/20 18:12:28 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

int						f_add(t_act *act, t_vec *vec, int i)
{
	act->f_p = *(int *)v_get(vec, ++i);
	act->s_p = *(int *)v_get(vec, ++i);
	act->t_p = *(int *)v_get(vec, ++i);
	return (i + 1);
}

int						f_sub(t_act *act, t_vec *vec, int i)
{
	act->f_p = *(int *)v_get(vec, ++i);
	act->s_p = *(int *)v_get(vec, ++i);
	act->t_p = *(int *)v_get(vec, ++i);
	return (i + 1);
}

int						f_and_second_part(t_act *act, t_vec *vec, int i, int id)
{
	if ((id & 0x30) == 0x20)
	{
		act->s_p = act->f_p;
		i = f_live(act, vec, i);
		act->t_p = act->f_p;
		act->f_p = act->s_p;
		act->s_p = act->t_p;
	}
	else if ((id & 0x30) == 0x10)
		act->s_p = *(int *)v_get(vec, i++);
	else if ((id & 0x30) == 0x30)
	{
		act->s_p = *(int *)v_get(vec, i);
		act->s_p <<= 8;
		++i;
		act->s_p += *(int *)v_get(vec, i++);
	}
	act->t_p = *(int *)v_get(vec, i++);
	return (i);
}

int						f_and(t_act *act, t_vec *vec, int i)
{
	int				id;

	id = *(int *)v_get(vec, i++);
	if ((id & 0xC0) == 0x40)
		act->f_p = *(int *)v_get(vec, i++);
	else if ((id & 0xc0) == 0x80)
		i = f_live(act, vec, i);
	else if ((id & 0xc0) == 0xc0)
	{
		act->f_p = *(int *)v_get(vec, i);
		act->f_p <<= 8;
		++i;
		act->f_p += *(int *)v_get(vec, i++);
	}
	return (f_and_second_part(act, vec, i, id));
}

int						f_st(t_act *act, t_vec *vec, int i)
{
	int id;

	id = *(int *)v_get(vec, i++);
	act->f_p = *(int *)v_get(vec, i++);
	if (id == 0x50)
		act->s_p = *(int *)v_get(vec, i++);
	else if (id == 0x70)
	{
		act->s_p = *(int *)v_get(vec, i);
		act->s_p <<= 8;
		++i;
		act->s_p += *(int *)v_get(vec, i++);
	}
	else
		error("Bad Action");
	return (i);
}
