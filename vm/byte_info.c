#include "../dep/includes/vm.h"

static void				write_bytes(t_vm *vm, char *dest, char *src, 
											size_t , int id)
{
	size_t				jump;
	size_t				i;
	t_binary			*b;
	t_champion			*champ;
	

	i = 0;
	jump = 0;
	if (dst != g_corewar.cycle_infos.arena)
		offset = dst - g_corewar.cycle_infos.arena;
	while (i < count)
	{
		dst[i] = src[i];
		byte = &g_corewar.cycle_infos.byte_infos[offset + i];
		byte->op = 50;
		if ((player = who_is_it(number)))
			byte->number = player->id;
		i++;
	}
}

void					write_range(char *src, char *pc, size_t range, int number)
{
	char	*mem;
	int		overflow;

	if ((mem = g_corewar.cycle_infos.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		write_bytes(mem, &src[range], overflow, number);
	}
	write_bytes(pc, src, range, number);
}
