/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/04/24 16:40:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_dbug(t_instruct *instr)
{
	int i;

	i = 0;
	ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode,
		instr->address);
	while (i < MAX_ARGS_NUMBER)
	{
		ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n",
			instr->params[i].type,
			instr->params[i].value,
			instr->params[i].init_val,
			instr->params[i].bytes);
		++i;
	}
}

char	get_opc(t_instruct *instr)
{
	int		i;
	char	conf;

	i = 0;
	conf = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (instr->params[i].type == T_REG)
			conf |= OCP_REG;
		else if (instr->params[i].type == T_DIR)
			conf |= OCP_DIR;
		else if (instr->params[i].type == T_IND)
			conf |= OCP_IND;
		else if (instr->params[i].type == T_LAB)
			conf |= OCP_DIR;
		if (i < 3)
			conf = conf << 2;
		++i;
	}
	return (conf);
}

int		get_progsize(t_champ *champ)
{
	t_instruct	*instr;
	int			size;

	size = 0;
	instr = champ->instructs;
	while (instr)
	{
		size += params_size(instr);
		if (g_op_tab[instr->opcode].opcode)
			++size;
		instr = instr->next;
	}
	return (size);
}