#include "vm.h"

void				ldi(t_oper *p, t_params args[3])
{
/*	t_reg	*dst_reg;
	int		offset;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	offset = (a + b) % IDX_MOD;
	if ((dst_reg = get_register(proc->reg, args[2].value)))
		read_range((char *)dst_reg, proc->pc + offset, REG_SIZE);
*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do ldi\n");
}

void				lfork(t_oper *p, t_params args[3])
{
/*	t_proc	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value);
*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do lfork\n");
}



void				lld(t_oper *p, t_params args[3])
{
/*	int		value;

	value = get_value(proc, args, 0, 1);
	store_register(get_register(proc->reg, args[1].value), (char *)&value);
	if (g_corewar.reg_error)
		return ;
	if (value != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do lld\n");
}

void				lldi(t_oper *p, t_params args[3])
{
/*	t_reg	*dst_reg;
	int		reg_value;
	int		offset;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 1);
	b = get_value(proc, args, 1, 1);
	if (g_corewar.reg_error)
		return ;
	offset = a + b;
	if ((dst_reg = get_register(proc->reg, args[2].value)))
		read_range((char *)dst_reg, proc->pc + offset, REG_SIZE);
	reg_value = 0;
	read_register(get_register(proc->reg, args[2].value), (char *)&reg_value);
	if (g_corewar.reg_error)
		return ;
	if (reg_value != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do lldi\n");
}