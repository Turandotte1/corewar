#include "../dep/includes/vm.h"

void						aff(t_vm *vm, t_oper *p, t_params args[3])
{
	int						aff;

	aff = 0;
	analyze_info(read_info(vm, p->r, args[0].value), (char *)&aff);
	if (!vm->error)
	{
		if (vm->v)
		{
//			vm->cycle.aff[0] = p->id;
//			vm->cycle.aff[1] = args[0].value;
//			vm->cycle.aff[2] = aff;
//			vm->cycle.aff[3] = p->carry;
		}
		else
			ft_printf("%c", aff);
	}
}
