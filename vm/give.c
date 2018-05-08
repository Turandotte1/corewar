/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:57:03 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/08 19:04:50 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int(*g_tab_fonctions[0x10])(t_act *act, t_vec *vec, int i) =
{f_live, f_ld, f_st, f_add, f_sub, f_and, f_and, f_and, f_zjmp,
	f_ldi, f_sti, f_fork, f_ld, f_ldi, f_fork, f_aff};

t_act		ini_struct(void)
{
	t_act act;

	act.act = 0;
	act.f_p = -1;
	act.s_p = -1;
	act.t_p = -1;
	return (act);
}

int			give_parameters(t_act *act, t_vec *vec, int i)
{
	if (act->act > 0x10 || act->act < 1)
		return (error("Unfounded action"));
	else
		return (g_tab_fonctions[act->act - 1](act, vec, i));
}

void		give_size(t_vec *vec, int *i, header_t *head)
{
	while (*(int *)v_get(vec, *i) == 0 && *i < v_size(vec))
		*i += 1;
	head->prog_size = *(int *)v_get(vec, *i);
	if (*i == 138)
	{
		head->prog_size <<= 8;
		*i += 1;
		head->prog_size += *(int *)v_get(vec, *i);
	}
	*i += 1;
	if (head->prog_size > CHAMP_MAX_SIZE)
		error("Size is over 9000");
}

void		give_comment(t_vec *vec, int *i, header_t *head)
{
	int y;

	y = 0;
	while (*(int *)v_get(vec, *i) != 0 && *i < v_size(vec))
	{
		head->comment[y++] = *(int *)v_get(vec, *i);
		*i += 1;
		if (y > COMMENT_LENGTH)
			error("Comment is too long");
	}
	head->comment[y] = '\0';
}

void		give_actions(t_vec *vec, t_vec *queue)
{
	t_vec	tmp;
	t_act	act;
	int		i;

	i = 2192;
	tmp = v_new(sizeof(t_act));
	while (i < v_size(vec))
	{
		act = ini_struct();
		act.act = *(int *)v_get(vec, i++);
		i = give_parameters(&act, vec, i);
		v_push(&tmp, &act);
	}
	v_push(queue, &tmp);
}
