/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:34:39 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 18:36:26 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/viz.h"
#include "../dep/includes/vm.h"

static void				note_binary(t_cycle *cw)
{
	int					i;
	t_binary			*b;
	char				*pc;

	i = 0;
	while (i < MEM_SIZE)
	{
		b = &cw->byte[i];
		b->pc = 0;
		if (g_vm.vizu & (RUN | NEXT))
		{
			b->live -= (b->live > 0) ? 1 : 0;
			b->op -= (b->op > 0) ? 1 : 0;
		}
		i++;
	}
	i = g_vm.hm_process;
	while (--i >= 0)
	{
		pc = g_vm.ops[i].pc;
		if (pc >= g_vm.arena + MEM_SIZE)
			cw->byte[0].pc |= 1;
		else
			cw->byte[pc - g_vm.arena].pc |= 1;
	}
}

void					draw_win(t_windows win[2])
{
	note_binary(&g_vm.cycle);
	arena_print(&win[0]);
	wrefresh(win[0].window);
	if (!(g_vm.vizu & RUN))
		g_vm.vizu = PAUSE;
}
