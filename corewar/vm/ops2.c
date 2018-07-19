/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:19:03 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/18 16:35:04 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						and(t_oper *p, t_params args[3])
{
	int						and;
	int						a;
	int						b;

	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	if (g_vm.error)
		return ;
	and = a & b;
	store_info(read_info(p->r, args[2].value), (char *)&and);
	if (g_vm.error)
		return ;
	p->carry = (and == 0) ? 1 : 0;
}

void						or(t_oper *p, t_params args[3])
{
	int						or;
	int						a;
	int						b;

	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	if (g_vm.error)
		return ;
	or = a | b;
	store_info(read_info(p->r, args[2].value), (char *)&or);
	if (g_vm.error)
		return ;
	p->carry = (or == 0) ? 1 : 0;
}

void						xor(t_oper *p, t_params args[3])
{
	int						xor;
	int						a;
	int						b;

	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	if (g_vm.error)
		return ;
	xor = a ^ b;
	store_info(read_info(p->r, args[2].value), (char *)&xor);
	if (g_vm.error)
		return ;
	p->carry = (xor == 0) ? 1 : 0;
}

void						zjmp(t_oper *p, t_params args[3])
{
//	ft_printf("I JUMP FOR %d\n", (short)args[0].value % IDX_MOD);
//	ft_printf("I am %ld\n", p->pc - g_vm.arena);
	if (p->carry == 1)
		move_players(p, (short)args[0].value % IDX_MOD);
	else
		move_players(p, 3);
	//ft_printf("I become %ld\n", p->pc - g_vm.arena);
	ft_putstr("je suis cycle ");
	ft_putnbr(g_vm.hm_cycles);
	ft_putstr(" ");
	print_memory((void*)p->pc, 8);
	ft_printf(" et la difference d adresse est de %d \n", p->pc - g_vm.arena);
}

void						ldi(t_oper *p, t_params args[3])
{
	t_reg					*dest;
	int						jump;
	int						a;
	int						b;

	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	if (g_vm.error)
		return ;
	jump = (a + b) % IDX_MOD;
	if ((dest = read_info(p->r, args[2].value)))
		read_through((char *)dest, p->pc + jump, REG_SIZE);
}
