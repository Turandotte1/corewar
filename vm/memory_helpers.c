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


void					write_info(t_reg r[REG_SIZE], char *pc, int champ_number)
{
	if (r)
		//write_range((char *)r, pc, REG_SIZE, champ_number);
		printf("writing here\n");
	champ_number = 2;
	pc = NULL;
	r = NULL;
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