/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:17:10 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/18 16:35:05 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						live(t_oper *p, t_params args[3])
{
	int						jump;
	t_cycle					*cycle;
	t_champion				*champ;

	p->live++;
	//ft_printf("#%d# \n", args[0].value);
	if ((champ = who_is_it(args[0].value)))
	{
		//ft_printf("et moi je suis le champion %d\n", champ->champ_id);
		cycle = &g_vm.cycle;
		jump = p->pc - g_vm.arena;
		if (jump >= 0 && jump < MEM_SIZE)
			g_vm.cycle.byte[jump].live = 50;
		cycle->last_live = champ->champ_id;
		champ->last_live = g_vm.hm_cycles;
		champ->cur_live++;
	//	ft_printf("je suis passe juste la\n");
	//	if (!(g_vm.v))
	//		ft_printf("Player %d (%s) is said to be alive\n",
	//							-champ->champ_id, champ->head.prog_name);
	}
}

void						ld(t_oper *p, t_params args[3])
{
	int						ld;

	ld = get_value(p, args, 0, 0);
	if (g_vm.error)
		return ;
	store_info(read_info(p->r, args[1].value), (char *)&ld);
	p->carry = (ld == 0) ? 1 : 0;
}

void						st(t_oper *p, t_params args[3])
{
	int						champ_id;

	//ft_printf("je suis rentre la!\n");
	if (args[1].type == T_IND)
	{
	//	ft_printf("%s %d \n", "je fais l autre chose", g_vm.hm_cycles);
		champ_id = 0;
		analyze_info(read_info(p->r, 1), (char *)&champ_id);
		write_info(read_info(p->r, args[0].value),
					p->pc + ((short)args[1].value) % IDX_MOD, champ_id);
	}
	if (args[1].type == T_REG)
	{
	//	ft_printf("%s %d \n", "je fais la chose", g_vm.hm_cycles);
		copy_info(read_info(p->r, args[1].value),
				read_info(p->r, args[0].value));
	}
}

void						add(t_oper *p, t_params args[3])
{
	int						sum;
	int						a;
	int						b;

	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	if (g_vm.error)
		return ;
	sum = a + b;
	store_info(read_info(p->r, args[2].value), (char *)&sum);
	if (g_vm.error)
		return ;
	p->carry = (sum == 0) ? 1 : 0;
}

void						sub(t_oper *p, t_params args[3])
{
	int						sub;
	int						a;
	int						b;

	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	if (g_vm.error)
		return ;
	sub = a - b;
	store_info(read_info(p->r, args[2].value), (char *)&sub);
	if (g_vm.error)
		return ;
	p->carry = (sub == 0) ? 1 : 0;
}
