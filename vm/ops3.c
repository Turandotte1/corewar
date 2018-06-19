#include "../dep/includes/vm.h"

void					or(t_vm *vm, t_oper *p, t_params args[3])
{
	int					sum;
	int					first;
	int					second;

	first = get_value(p, args, 0, 0);
	second = get_value(p, args, 1, 0);
	if (vm->error)
		return ;
	sum = first | second;
//	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (vm->error)
		return ;
	p->carry = (sum != 0) ? 0 : 1;
}

void					st(t_vm *vm, t_oper *p, t_params args[3])
{
	//int					champ_number;

	vm->error = 0;
	//if (args[1].type == T_IND)
	//{
	//	champ_number = 0;
	//	read_register(get_register(proc->reg, 1), (char *)&champ_number);
	//	write_register(get_register(proc->reg, args[0].value),
		//			proc->pc + ((short)args[1].value) % IDX_MOD, champ_number);
	//}
	if (args[1].type == T_REG)
	{
	//	copy_register(get_register(proc->reg, args[1].value),
	//			get_register(proc->reg, args[0].value));
		p->carry = 1;
	//champ_number = champ_number;
		ft_printf("i do st\n");
	}
}

void					sti(t_vm *vm, t_oper *p, t_params args[3])
{
//	int					champ_num;
	int					jump;
	int					first;
	int					second;

	first = get_value(p, args, 1, 0);
	second = get_value(p, args, 2, 0);
	if (vm->error)
		return ;
	jump = (first + second) % IDX_MOD;
//	champ_num = 0;
//	read_register(get_register(proc->reg, 1), (char *)&champ_number);
//	write_register(get_register(proc->reg, args[0].value), proc->pc + offset,
//			
													//champ_num);
//	(void*)jump;
//	champ_num = champ_num;
	ft_printf("i do sti\n");
}

void					sub(t_vm *vm, t_oper *p, t_params args[3])
{
	int					sum;
	int					first;
	int					second;

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

void					xor(t_vm *vm, t_oper *p, t_params args[3])
{
	int					sum;
	int					first;
	int					second;

	first = get_value(p, args, 0, 0);
	second = get_value(p, args, 1, 0);
	if (vm->error)
		return ;
	sum = first ^ second;
//	store_register(get_register(proc->reg, args[2].value), (char *)&sum);
	if (vm->error)
		return ;
	if (sum != 0)
	p->carry = (sum != 0) ? 0 : 1;
}
