/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:19:03 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/12 17:19:28 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						and(t_vm *vm, t_oper *p, t_params args[3])
{
	int						and;
	int						a;
	int						b;

	a = get_value(vm, p, args, 0, 0);
	b = get_value(vm, p, args, 1, 0);
	if (vm->error)
		return ;
	and = a & b;
	store_info(read_info(vm, p->r, args[2].value), (char *)&and);
	if (vm->error)
		return ;
	p->carry = (and == 0) ? 1 : 0;
}

void						or(t_vm *vm, t_oper *p, t_params args[3])
{
	int						or;
	int						a;
	int						b;

	a = get_value(vm, p, args, 0, 0);
	b = get_value(vm, p, args, 1, 0);
	if (vm->error)
		return ;
	or = a | b;
	store_info(read_info(vm, p->r, args[2].value), (char *)&or);
	if (vm->error)
		return ;
	p->carry = (or == 0) ? 1 : 0;
}

void						xor(t_vm *vm, t_oper *p, t_params args[3])
{
	int						xor;
	int						a;
	int						b;

	a = get_value(vm, p, args, 0, 0);
	b = get_value(vm, p, args, 1, 0);
	if (vm->error)
		return ;
	xor = a ^ b;
	store_info(read_info(vm, p->r, args[2].value), (char *)&xor);
	if (vm->error)
		return ;
	p->carry = (xor == 0) ? 1 : 0;
}

void						zjmp(t_vm *vm, t_oper *p, t_params args[3])
{
	if (p->carry == 1)
		move_players(vm, p, (short)args[0].value % IDX_MOD);
	else
		move_players(vm, p, 3);
}

void						ldi(t_vm *vm, t_oper *p, t_params args[3])
{
	t_reg					*dest;
	int						jump;
	int						a;
	int						b;

	a = get_value(vm, p, args, 0, 0);
	b = get_value(vm, p, args, 1, 0);
	if (vm->error)
		return ;
	jump = (a + b) % IDX_MOD;
	if ((dest = read_info(vm, p->r, args[2].value)))
		read_through(vm, (char *)dest, p->pc + jump, REG_SIZE);
}
