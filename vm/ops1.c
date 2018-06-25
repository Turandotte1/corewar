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
			ft_printf("Player %d (%s) is said to be alive\n",
								-champ->champ_id, "insert name here");
	}
}

void						ld(t_vm *vm, t_oper *p, t_params args[3])
{
	int						val;

	val = get_value(vm, p, args, 0, 0);
	store_info(read_info(vm, p->r, args[1].value), (char *)&val);
	if (vm->error)
		return ;
	p->carry = (val == 0) ? 1 : 0;
	printf("i do ld\n");
}

void						st(t_vm *vm, t_oper *p, t_params args[3])
{
	int						champ_id;

	if (args[1].type == T_IND)
	{
		champ_id = 0;
		analyze_info(read_info(vm, p->r, 1), (char *)&champ_id);
		write_info(vm, read_info(vm, p->r, args[0].value),
					p->pc + ((short)args[1].value) % IDX_MOD, champ_id);
	}
	if (args[1].type == T_REG)
	{
		copy_info(read_info(vm, p->r, args[1].value),
				read_info(vm, p->r, args[0].value));
	}
	printf("i do st\n");
}

void						add(t_vm *vm, t_oper *p, t_params args[3])
{
	int						sum;
	int						a;
	int						b;

	a = get_value(vm, p, args, 0, 0);
	b = get_value(vm, p, args, 1, 0);
	if (vm->error)
		return ;
	sum = a + b;
	store_info(read_info(vm, p->r, args[2].value), (char *)&sum);
	if (vm->error)
		return ;
	p->carry = (sum == 0) ? 1 : 0;
	printf("i do add\n");
}

void						sub(t_vm *vm, t_oper *p, t_params args[3])
{
	int						sub;
	int						a;
	int						b;

	a = get_value(vm, p, args, 0, 0);
	b = get_value(vm, p, args, 1, 0);
	if (vm->error)
		return ;
	sub = a - b;
	store_info(read_info(vm, p->r, args[2].value), (char *)&sub);
	if (vm->error)
		return ;
	p->carry = (sub == 0) ? 1 : 0;
	printf("i do sub\n");
}

