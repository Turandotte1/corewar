#include "../dep/includes/vm.h"

int							get_value(t_oper *p, t_params *args, int idx, int long_op)
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
		get_register(p->r, value);
	else if (type & T_IND)
	{
		value = (long_op) ? (short)value : ((short)value) % IDX_MOD;
		ft_bzero(&buf, DIR_SIZE);
//		read_range((char *)&buf, p->pc + value, DIR_SIZE);
	}
	return (ret);
}

t_reg						*get_register(t_reg *registers, int idx)
{
	if (idx < 1 || idx > REG_NUMBER)
	{
//		g_corewar.reg_error = 1;
		return (NULL);
	}
	return (&registers[idx - 1]);
}

/*void						read_range(char *dst, char *pc, size_t range)
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
		ft_memcpy((void *)&dst[range], (void *)mem, overflow);
	}
	ft_memcpy((void *)dst, (void *)pc, range);
}*/
