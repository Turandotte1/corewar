#include "vm.h"

void					zjmp(t_vm *vm, t_oper *p, t_params args[3])
{
	if (p->carry == 1)
		move_players(vm, p, (short)args[0].value % IDX_MOD);
	else
		move_players(vm, p, 3);
}