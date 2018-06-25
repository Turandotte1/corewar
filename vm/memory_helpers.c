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


void					write_info(t_vm *vm, t_reg r[REG_SIZE], char *pc, int champ_number)
{
	if (r)
		binary_write(vm, (char *)r, pc, REG_SIZE, champ_number);
}

void 					copy_info(t_reg dest[REG_SIZE], t_reg src[REG_SIZE])
{
	if (dest && src)
		ft_memcpy((void *)dest, (void *)src, REG_SIZE);
}
