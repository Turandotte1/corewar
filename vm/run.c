/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:06:22 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 16:22:14 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"
#include "../dep/includes/viz.h"

static void				count_lives(size_t *hm_live, size_t *hm_die)
{
	int					i;

	*hm_live = 0;
	*hm_die = 0;
	i = g_vm.hm_process;
	while (--i >= 0)
	{
		if (g_vm.ops[i].live)
			*hm_live += g_vm.ops[i].live;
		else
			(hm_die)++;
	}
}

static int				i_am_alive(void)
{
	size_t				live_count;
	size_t				die_count;
	int					i;

	count_lives(&live_count, &die_count);
	if (die_count > 0)
		kill_process(g_vm.hm_process - die_count);
	else
	{
		i = g_vm.hm_process;
		while (--i >= 0)
			g_vm.ops[i].live = 0;
	}
	i = g_vm.champs;
	while (--i >= 0)
		g_vm.champ[i].cur_live = 0;
	return (live_count >= NBR_LIVE);
}

static void				showmust_go_on(void)
{
	t_oper				*current;
	int					cycles;
	int					opcode;
	int					jump;

	cycles = g_vm.hm_process;
	while (--cycles >= 0)
	{
		current = &g_vm.ops[cycles];
		if (current->waiting < 0)
		{
			opcode = (int)read_adress_info(current->pc) - 1;
			if (opcode < OPS && opcode >= 0)
			{
				current->act = &g_tab[opcode];
				current->waiting = g_tab[opcode].cycles;
			}
		}
		if (--current->waiting <= 0)
		{
			jump = which_operation(current);
			move_players(&g_vm.ops[cycles], jump);
		}
	}
}

int						someone_is_alive(void)
{
	if (g_vm.dump > 0 && g_vm.hm_cycles >= g_vm.dump_nb)
	{
		print_arena(g_vm.arena);
		exit(EXIT_SUCCESS);
	}
	g_vm.hm_cycles++;
	showmust_go_on();
	if (g_vm.hm_cycles >= g_vm.cycle.check)
	{
		g_vm.cycle.cur += (i_am_alive()) ? MAX_CHECKS : 1;
		g_vm.cycle.check = g_vm.hm_cycles + g_vm.cycle.to_die;
	}
	if (g_vm.cycle.cur >= MAX_CHECKS)
	{
		g_vm.cycle.cur = 0;
		g_vm.cycle.to_die -= CYCLE_DELTA;
		g_vm.cycle.check -= CYCLE_DELTA;
	}
	return (g_vm.hm_process <= 0 || g_vm.cycle.to_die <= 0) ? 0 : 1;
}

void					players_are_ready(void)
{
	t_champion			*win;

	g_vm.cycle.to_die = CYCLE_TO_DIE;
	g_vm.cycle.check = CYCLE_TO_DIE;
	g_vm.cycle.cur = 0;
	if (g_vm.v)
		start_ncurse_mode();
	else
	{
		while (someone_is_alive())
			;
	}
	if ((win = who_is_it(g_vm.cycle.last_live)))
		ft_printf("Contestant %i, \"%s\", has won !\n", -win->champ_id,
			win->head.prog_name);
	else
	{
		ft_printf("Contestant %i, \"%s\", has won !\n", -g_vm.champ->champ_id,
			g_vm.champ->head.prog_name);
	}
}
