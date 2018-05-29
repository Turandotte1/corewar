#include "vm.h"

void	add_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	sum = a + b;
	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (g_corewar.reg_error)
		return ;
	if (sum != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}

void	aff_op(t_proc *proc, t_op_arg args[3])
{
	int		value;

	if (g_corewar.flags & FLAG_HIDE)
		return ;
	value = 0;
	read_register(get_register(proc->reg, args[0].value), (char *)&value);
	if (!g_corewar.reg_error)
	{
		if (g_corewar.flags & FLAG_NCUR)
		{
			g_corewar.cycle_infos.aff[0] = proc->id;
			g_corewar.cycle_infos.aff[1] = args[0].value;
			g_corewar.cycle_infos.aff[2] = value;
			g_corewar.cycle_infos.aff[3] = proc->carry;
		}
		else
			ft_printf("%c", value);
	}
}

void	and_op(t_proc *proc, t_op_arg args[3])
{
	int		sum;
	int		a;
	int		b;

	a = get_value(proc, args, 0, 0);
	b = get_value(proc, args, 1, 0);
	if (g_corewar.reg_error)
		return ;
	sum = a & b;
	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (g_corewar.reg_error)
		return ;
	if (sum != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}

void	fork_op(t_proc *proc, t_op_arg args[3])
{
	t_proc	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value % IDX_MOD);
}

void	ld_op(t_proc *proc, t_op_arg args[3])
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