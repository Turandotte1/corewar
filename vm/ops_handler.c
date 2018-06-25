#include "../dep/includes/vm.h"

static void					write_b(t_vm *vm, char *dest, char *src, 
											size_t count, int id)
{
	size_t					jump;
	size_t					i;
	t_binary				*b;
	t_champion				*champ;
		
	i = 0;
	jump = 0;
	if (dest != vm->arena)
		jump = dest - vm->arena;
	while (i < count)
	{
		dest[i] = src[i];
		b = &vm->cycle.byte[jump + i];
		b->op = 50;
		if ((champ = who_is_it(vm, id)))
			b->id = champ->champ_id;
		i++;
	}
}

void						binary_write(t_vm *vm, char *src, char *pc, 
										size_t range, int number)
{
	char					*mem;
	int						overflow;

	if ((mem = vm->arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		write_b(vm, mem, &src[range], overflow, number);
	}
	write_b(vm, pc, src, range, number);
}

int							get_value(t_vm *vm, t_oper *p, t_params *args, int idx, int long_op)
{
	char					buf[DIR_SIZE];
	t_arg_type				type;
	int						value;
	int						ret;

	ret = 0;
	type = args[idx].type;
	value = args[idx].value;
	if (!(type & p->act->args_types[idx]))
		return (0);
	else if (type & T_DIR)
		ret = (p->act->dir_short) ? (short)value : value;
	else if (type & T_REG)
		read_info(NULL, p->r, value);
	else if (type & T_IND)
	{
		value = (long_op) ? (short)value : ((short)value) % IDX_MOD;
		ft_bzero(&buf, DIR_SIZE);
		read_through(vm, (char *)&buf, p->pc + value, DIR_SIZE);
		convert_endian((char*)&ret, (char *)&buf, DIR_SIZE);
	}
	return (ret);
}

void						read_through(t_vm *vm, char *dst, char *pc, size_t range)
{
	char					*mem;
	int						overflow;

	if ((mem = vm->arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		ft_memcpy((void *)&dst[range], (void *)mem, overflow);
	}
	ft_memcpy((void *)dst, (void *)pc, range);
}



char						read_adress_info(char *address)
{
	int						overflow;

	if ((overflow = address - (address + MEM_SIZE)) >= 0)
		return (address[overflow]);
	return (*address);
}

