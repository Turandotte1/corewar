/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:45:12 by glegendr          #+#    #+#             */
/*   Updated: 2018/06/18 20:38:31 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

int(*g_tab_fonctions[0x10])(t_act *act, t_vec *vec, int i) =
{f_live, f_ld, f_st, f_add, f_sub, f_and, f_and, f_and, f_zjmp,
	f_ldi, f_sti, f_fork, f_ld, f_ldi, f_fork, f_aff};

static int				give_parameters(t_act *act, t_vec *vec, int i)
{
	if (act->act > 0x10 || act->act < 1)
		return (error("Unfounded action"));
	else
		return (g_tab_fonctions[act->act - 1](act, vec, i));
}

void					give_actions(t_vec *vec, t_vec *queue)
{
	int					i;
	t_vec				tmp;
	t_act				act;

	i = 2192;
	tmp = v_new(sizeof(t_act));
	while (i < v_size(vec))
	{
		act = init_struct();
		act.act = *(int *)v_get(vec, i++);
		i = give_parameters(&act, vec, i);
		v_push(&tmp, &act);
	}
	v_push(queue, &tmp);
}
