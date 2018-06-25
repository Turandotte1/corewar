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
		if (jump >= 0 && jump < MEM_SIZE)
			vm->cycle.byte[jump].live = 50;
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
//	store_info(read_info(vm, p->r, args[1].value), (char *)&val);
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

void						add(t_vm *vm, t_oper *p, t_params args[3])
{
	int						sum;
	int						a;
	int						b;

	vm->error = 0;
	a = get_value(p, args, 0, 0);
	b = get_value(p, args, 1, 0);
	sum = a + b;
//	store_register((char*)get_register(p->r, args[2].value), (char *)&sum, REG_SIZE);
	p->carry = (sum != 0) ? 0 : 1;
	printf("i do add\n");
}

void						sub(t_vm *vm, t_oper *p, t_params args[3])
{
	int						sum;
	int						first;
	int						second;

	first = get_value(p, args, 0, 0);
	second = get_value(p, args, 1, 0);
	if (vm->error)
		return ;
	sum = first - second;
//	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (vm->error)
		return ;
	p->carry = (sum != 0) ? 0 : 1;
	printf("i do sub\n");
}

