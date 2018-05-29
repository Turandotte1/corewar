#include "vm.h"

char		read_byte(char *addr, char *zone)
{
	int		overflow;

	if ((overflow = addr - (zone + MEM_SIZE)) >= 0)
		return (zone[overflow]);
	printf("ADDR = %c\n", *addr);
	return (*addr);
}

void					war_start(t_vm *vm)
{
	int 				i;
	int 				j;
	int					start;
	int					opcode;

	
	i = 0;
	j = 1;
	start = 0;
	printf(" CHAMP %s\n", vm->champ[1].ch);
	printf(" CHAMP %s\n", vm->champ[2].ch);
	printf(" CHAMP %s\n", vm->champ[3].ch);
	printf(" CHAMP %s\n", vm->champ[4].ch);
//	ft_bzero(vm->arena, MEM_SIZE);
	while (i < vm->champs)
	{
		//create process for each champ;
		start = MEM_SIZE / vm->champs * i;
		printf("START = %d\n", start);
		ft_memcpy(&vm->arena[start], vm->champ[j].ch,
				vm->champ[j].len);
		printf("%d\n", vm->champ[j].len);
		vm->ops[j].pc = &vm->arena[start];
		printf("%d pc %s\n", i, vm->ops[j].pc);
		j++;
		i++;
	}
	printf(" CHAMP 1%s\n", vm->champ[1].ch);
	printf(" CHAMP 1%s\n", vm->champ[2].ch);
	printf(" CHAMP 1%s\n", vm->champ[3].ch);
	printf(" CHAMP 1%s\n", vm->champ[4].ch);
	printf("ARENA = %s\n", vm->arena);
//	vm->hm_process = vm->champs;
	vm->cycle.to_die = CYCLE_TO_DIE;
	vm->cycle.cur = CYCLE_TO_DIE;
	vm->cycle.check = 0;
	opcode = 0xFF & (read_byte(vm->ops[1].pc + 1, vm->arena) - 87); //if a-f;
//	if (vm->v)
//		start_ncurse_mode(vm);
//	else
//	{
//		opcode = 0;
//		while (is_alive(vm))
//	}	
}

