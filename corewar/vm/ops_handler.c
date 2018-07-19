/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:21:14 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/18 16:45:08 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

static void					write_b(char *dest, char *src, 
											size_t count, int id)
{
	size_t					jump;
	size_t					i;
	t_binary				*b;
	t_champion				*champ;
		
	i = 0;
	jump = 0;
	if (dest != g_vm.arena)
		jump = dest - g_vm.arena;
	while (i < count)
	{
		dest[i] = src[i];
		b = &g_vm.cycle.byte[jump + i];
		b->op = 50;
		if ((champ = who_is_it(id)))
			b->id = champ->id;
		i++;
	}
}

void						binary_write(char *src, char *pc, 
										int number)
{
	char					*mem;
	int						overflow;
	int 					range;

	range = REG_SIZE;
	if ((mem = g_vm.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		write_b(mem, &src[range], overflow, number);
	}
	write_b(pc, src, range, number);
}

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
		analyze_info(read_info(p->r, value), (char *)&ret);
	else if (type & T_IND)
	{
		value = (long_op) ? (short)value : ((short)value) % IDX_MOD;
		ft_bzero(&buf, DIR_SIZE);
		read_through((char *)&buf, p->pc + value, DIR_SIZE);
		convert_endian((char*)&ret, (char *)&buf, DIR_SIZE);
	}
	return (ret);
}

void						read_through(char *dest, char *pc, size_t range)
{
	char					*mem;
	int						overflow;

	if ((mem = g_vm.arena) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		ft_memcpy((void *)&dest[range], (void *)mem, overflow);
	}
	ft_memcpy((void *)dest, (void *)pc, range);
}

char						read_adress_info(char *adress)
{
	int						overflow;

	if ((overflow = adress - (g_vm.arena + MEM_SIZE)) >= 0)
		return (g_vm.arena[overflow]);
	return (*adress);
}
