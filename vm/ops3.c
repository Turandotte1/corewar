#include "../dep/includes/vm.h"

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

void						fork_o(t_vm *vm, t_oper *p, t_params args[3])
{
	t_oper					*new_p;

	new_p = NULL;
	new_p = make_process(vm, new_p->pc, p);
	move_players(vm, new_p, (short)args[0].value % IDX_MOD);
	printf("i do fork\n");
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

void						lfork(t_vm *vm, t_oper *p, t_params args[3])
{
	t_oper					*new_p;

	new_p = make_process(vm, p->pc, p);
	move_players(vm, new_p, (short)args[0].value);
	printf("i do lfork\n");
}
























