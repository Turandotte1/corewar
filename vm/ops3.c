/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:19:57 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/12 17:20:27 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						sti(t_vm *vm, t_oper *p, t_params args[3])
{
	int						champ_id;
	int						jump;
	int						a;
	int						b;

	a = get_value(vm, p, args, 1, 0);
	b = get_value(vm, p, args, 2, 0);
	if (vm->error)
		return ;
	jump = (a + b) % IDX_MOD;
	champ_id = 0;
	analyze_info(read_info(vm, p->r, 1), (char *)&champ_id);
	write_info(vm, read_info(vm, p->r, args[0].value), p->pc + jump, champ_id);
}

void						fork_o(t_vm *vm, t_oper *p, t_params args[3])
{
	t_oper					*new_p;

	new_p = NULL;
	new_p = make_process(vm, p->pc, p);
	move_players(vm, new_p, (short)args[0].value % IDX_MOD);
}

void						lld(t_vm *vm, t_oper *p, t_params args[3])
{
	int						lld;

	lld = get_value(vm, p, args, 0, 1);
	store_info(read_info(vm, p->r, args[1].value), (char *)&lld);
	if (vm->error)
		return ;
	p->carry = (lld == 0) ? 1 : 0;
}

void						lldi(t_vm *vm, t_oper *p, t_params args[3])
{
	t_reg					*dest;
	int						lldi;
	int						jump;
	int						a;
	int						b;

	a = get_value(vm, p, args, 0, 1);
	b = get_value(vm, p, args, 1, 1);
	if (vm->error)
		return ;
	jump = a + b;
	if ((dest = read_info(vm, p->r, args[2].value)))
		read_through(vm, (char *)dest, p->pc + jump, REG_SIZE);
	lldi = 0;
	analyze_info(read_info(vm, p->r, args[2].value), (char *)&lldi);
	if (vm->error)
		return ;
	p->carry = (lldi == 0) ? 1 : 0;
}

void						lfork(t_vm *vm, t_oper *p, t_params args[3])
{
	t_oper					*new_p;

	new_p = make_process(vm, p->pc, p);
	move_players(vm, new_p, (short)args[0].value);
}
