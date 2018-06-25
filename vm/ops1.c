#include "../dep/includes/vm.h"

void						live(t_vm *vm, t_oper *p, t_params args[3])
{
	int						jump;
	t_cycle					*cycle;
	t_champion				*champ;
	
	p->live++;
	if ((champ = who_is_it(vm, args[0].value)))
	{
		cycle = &vm->cycle;
		jump = p->pc - vm->arena;
//		if (jump >= 0 && jump < MEM_SIZE)
//			->byte_infos[jump].live = 50;
		cycle->last_live = champ->champ_id;
		champ->last_live = vm->hm_cycles;
		champ->cur_live++;
		if (!(vm->v))
			ft_printf("A process tells player %i(%s) is alive\n",
								champ->champ_id, "insert name here");
	}
}

void						ld(t_vm *vm, t_oper *p, t_params args[3])
{
	int						val;

	val = get_value(p, args, 0, 0);
	store(read_info(vm, p->r, args[1].value), (char *)&val);
	if (vm->error)
		return ;
	p->carry = (val == 0) ? 1 : 0;
//	printf("i do ld\n");
}

void						st(t_vm *vm, t_oper *p, t_params args[3])
{
	int					champ_number;

	if (args[1].type == T_IND)
	{
		champ_number = 0;
		analyze_info(read_info(vm, p->r, 1), (char *)&champ_number);
	//	write_register(get_register(proc->reg, args[0].value),
		//			proc->pc + ((short)args[1].value) % IDX_MOD, champ_number);
	}
	if (args[1].type == T_REG)
	{
	//	copy_register(get_register(proc->reg, args[1].value),
	//			get_register(proc->reg, args[0].value));
		p->carry = 1;
	//champ_number = champ_number;
		ft_printf("i do st\n");
	}
}

void					add(t_vm *vm, t_oper *p, t_params args[3])
{
	int					sum;
	int					a;
	int					b;

	vm->error = 0;
	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	sum = a + b;
//	store_register((char*)get_register(p->r, args[2].value), (char *)&sum, REG_SIZE);
	p->carry = (sum != 0) ? 0 : 1;
	printf("i do add\n");
}



void						aff(t_vm *vm, t_oper *p, t_params args[3])
{
	int		value;

	value = 0;
//	read_register(get_register(proc->reg, args[0].value), (char *)&value);
	if (!vm->error)
	{
//		if (g_corewar.flags & FLAG_NCUR)
//		{
//			corewar.cycle_infos.aff[0] = proc->id;
//			corewar.cycle_infos.aff[1] = args[0].value;
//			corewar.cycle_infos.aff[2] = value;
//			corewar.cycle_infos.aff[3] = proc->carry;
//		}
//		else
			ft_printf("%c", value);
	}
	p->carry = 1;
	args[2].value = 0;
	printf("i do aff\n");
}

void						and(t_vm *vm, t_oper *p, t_params args[3])
{
	int		sum;
	int		a;
	int		b;

	vm->error = 0;
	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
//	if (vm->error)
//		return ;
	sum = a & b;
//	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
//	if (vm->error)
//		return ;
	if (sum != 0)
		p->carry = 0;
	else
		p->carry = 1;
	printf("i do and\n");
}

void						fork_o(t_vm *vm, t_oper *p, t_params args[3])
{
	t_oper					*new_p;

	new_p = NULL;
	new_p = make_process(vm, new_p->pc, p);
	move_players(vm, new_p, (short)args[0].value % IDX_MOD);
	printf("i do fork\n");
}