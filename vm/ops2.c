#include "../dep/includes/vm.h"

void						ld(t_vm *vm, t_oper *p, t_params args[3])
{
	int						val;

	val = get_value(p, args, 0, 0);
//	store_register(get_register(p->reg, args[1].value), (char *)&value);
	if (vm->error)
		return ;
	p->carry = (val != 0) ? 0 : 1;
	printf("i do ld\n");
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

void						lfork(t_vm *vm, t_oper *p, t_params args[3])
{
	t_oper					*new_p;

	new_p = make_process(vm, p->pc, p);
	move_players(vm, new_p, (short)args[0].value);
	printf("i do lfork\n");
}

void						lld(t_vm *vm, t_oper *p, t_params args[3])
{
	int						val;

	val = get_value(p, args, 0, 1);
//	store_register(get_register(proc->reg, args[1].value), (char *)&value);
	if (vm->error)
		return ;
	p->carry = (val != 0) ? 0 : 1;
	printf("i do lld\n");
}

void						lldi(t_vm *vm, t_oper *p, t_params args[3])
{
//	t_reg					*dest;
	int						reg_val;
	//int						jump;
	//int						first;
	//int						second;

	//first = get_value(p, args, 0, 1);
	//second = get_value(p, args, 1, 1);
		(void) p;
	(void) args;
if (vm->error)
		return ;
	//jump = first + second;
//	if ((dest = get_register(p->reg, args[2].value)))
//		read_range((char *)dst_reg, proc->pc + offset, REG_SIZE);
	reg_val = 0;
//	read_register(get_register(proc->reg, args[2].value), (char *)&reg_value);
	if (vm->error)
		return ;
	p->carry = (reg_val != 0 ) ? 0 : 1;
	printf("i do lldi\n");
}
