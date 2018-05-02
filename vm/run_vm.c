#include "corewar_vm.h"

void					lfork_op(t_oper *proc, t_op_arg args[3])
{
	t_oper	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value);
}

void					ld_op(t_proc *proc, t_op_arg args[3])
{
	int		value;

	value = get_value(proc, args, 0, 0);
	store_register(get_register(proc->reg, args[1].value), (char *)&value);
	if (g_corewar.reg_error)
		return ;
	if (value != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}

void					fork_op(t_proc *proc, t_op_arg args[3])
{
	t_proc	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value % IDX_MOD);
}

void					zjmp_op(t_proc *proc, t_op_arg args[3])
{
	if (proc->carry == 1)
		process_move(proc, (short)args[0].value % IDX_MOD);
	else
		process_move(proc, 3);
}

void					xor_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	sum = a ^ b;
	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (g_corewar.reg_error)
		return ;
	if (sum != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}

void					sub_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	sum = a - b;
	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (g_corewar.reg_error)
		return ;
	if (sum != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}
void					sti_op(t_proc *proc, t_op_arg args[3])
{
	int		champ_number;
	int		offset;
	int		a;
	int		b;

	a = get_value(proc, args, 1, 0);
	b = get_value(proc, args, 2, 0);
	if (g_corewar.reg_error)
		return ;
	offset = (a + b) % IDX_MOD;
	champ_number = 0;
	read_register(get_register(proc->reg, 1), (char *)&champ_number);
	write_register(get_register(proc->reg, args[0].value), proc->pc + offset,
																champ_number);
}