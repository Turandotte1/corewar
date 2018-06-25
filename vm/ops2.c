#include "../dep/includes/vm.h"

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

void					zjmp(t_vm *vm, t_oper *p, t_params args[3])
{
	if (p->carry == 1)
		move_players(vm, p, (short)args[0].value % IDX_MOD);
	else
		move_players(vm, p, 3);
//	printf("i do zjump\n");
}

void						ldi(t_vm *vm, t_oper *p, t_params args[3])
{
//	t_reg					*dest;
	//int						jump;
	//int						first;
	//int						second;

	//first = get_value(p, args, 0, 0);
	//second = get_value(p, args, 1, 0);
	(void) p;
	(void) args;
	if (vm->error)
		return ;
	//jump = (first + second) % IDX_MOD;
//	if ((dst_reg = get_register(proc->reg, args[2].value)))
//		read_range((char *)dst_reg, proc->pc + offset, REG_SIZE);
	printf("i do ldi\n");
}

