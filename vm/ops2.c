#include "vm.h"

void	ldi_op(t_proc *proc, t_op_arg args[3])
{
	t_reg	*dst_reg;
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
}

void	lfork_op(t_proc *proc, t_op_arg args[3])
{
	t_proc	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value);
}

void		live_op(t_proc *proc, t_op_arg args[3])
{
	t_cycle_infos	*infos;
	t_player		*player;
	int				offset;

	proc->live++;
	if ((player = find_player(args[0].value)))
	{
		infos = &g_corewar.cycle_infos;
		offset = proc->pc - infos->arena;
		if (offset >= 0 && offset < MEM_SIZE)
			infos->byte_infos[offset].live = 50;
		infos->last_live = player->number;
		player->last_live = infos->count;
		player->current_lives++;
		if (!(g_corewar.flags & FLAG_NCUR))
			ft_printf(STR_LIVE_EXEC, player->number, player->name);
	}
}

void	lld_op(t_proc *proc, t_op_arg args[3])
{
	int		value;

	value = get_value(proc, args, 0, 1);
	store_register(get_register(proc->reg, args[1].value), (char *)&value);
	if (g_corewar.reg_error)
		return ;
	if (value != 0)
		proc->carry = 0;
	else
		proc->carry = 1;
}

void	lldi_op(t_proc *proc, t_op_arg args[3])
{
	t_reg	*dst_reg;
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
}