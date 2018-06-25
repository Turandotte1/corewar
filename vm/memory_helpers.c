/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:11:21 by glegendr          #+#    #+#             */
/*   Updated: 2018/06/20 18:11:24 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

t_reg					*read_info(t_vm *vm, t_reg r[REG_SIZE], int i)
{
	if (i < 1 || i > REG_NUMBER)
	{
		vm->error = 1;
		return (NULL);
	}
	return (&r[i - 1]);
}

char					read_adress_info(char *address)
{
	int					overflow;

	if ((overflow = address - (address + MEM_SIZE)) >= 0)
		return (address[overflow]);
	return (*address);
}

void					store_info(t_reg r[REG_SIZE], char *val)
{
	if (r)
		convert_endian((char *)r, val, REG_SIZE);
}



void					analyze_info(t_reg r[REG_SIZE], char *val)
{
	if (r)
		convert_endian(val, (char *)r, REG_SIZE);
}

static void				write_bytes(char *dst, char *src, size_t count, int number)
{
	t_byte_infos	*byte;
	t_player		*player;
	size_t			offset;
	size_t			i;

	i = 0;
	offset = 0;
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

void					write_info(t_reg r[REG_SIZE], char *pc, int champ_number)
{
	if (r)
		write_range((char *)r, pc, REG_SIZE, champ_number);
}







/*void		read_register(t_reg reg[REG_SIZE], char *value)
{
	if (reg)
		swap_endianess(value, (char *)reg, REG_SIZE);
}

void		store_register(t_reg reg[REG_SIZE], char *value)
{
	if (reg)
		swap_endianess((char *)reg, value, REG_SIZE);
}



void		copy_register(t_reg r1[REG_SIZE], t_reg r2[REG_SIZE])
{
	if (r1 && r2)
		ft_memcpy((void *)r1, (void *)r2, REG_SIZE);
}*/