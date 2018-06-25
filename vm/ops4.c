#include "../dep/includes/vm.h"

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