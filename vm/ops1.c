#include "vm.h"

void						add(t_oper *p, t_params args[3])
{
	int		sum;
	int		a;
	int		b;

	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	sum = a + b;
	store_register((char*)get_register(p->r, args[2].value), (char *)&sum, REG_SIZE);
	if (sum != 0)
		p->carry = 0;
	else
		p->carry = 1;
	printf("i do add\n");
}

void					live(t_oper *p, t_params args[3])
{
/*	t_cycle_infos	*infos;
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
	*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do live\n");

}

void						aff(t_oper *p, t_params args[3])
{
/*	int		value;

	if (g_corewar.flags & FLAG_HIDE)
		return ;
	value = 0;
	read_register(get_register(proc->reg, args[0].value), (char *)&value);
	if (!g_corewar.reg_error)
	{
		if (g_corewar.flags & FLAG_NCUR)
		{
			corewar.cycle_infos.aff[0] = proc->id;
			corewar.cycle_infos.aff[1] = args[0].value;
			corewar.cycle_infos.aff[2] = value;
			corewar.cycle_infos.aff[3] = proc->carry;
		}
		else
			ft_printf("%c", value);
	}
*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do aff\n");
}

void						and(t_oper *p, t_params args[3])
{
/*	int		sum;
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
*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do live\n");
}

void						fork_o(t_oper *p, t_params args[3])
{
/*	t_proc	*new_proc;

	new_proc = process_create(proc->pc, proc);
	process_move(new_proc, (short)args[0].value % IDX_MOD);
*/
	p->carry = 1;
	args[2].value = 0;
	printf("i do fork\n");
}

void						ld(t_oper *p, t_params args[3])
{
/*	int		value;

	value = get_value(proc, args, 0, 0);
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
	printf("i do ld\n");
}