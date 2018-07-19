/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_analyser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:48:45 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 16:19:43 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

static void						which_param(t_params *arg, char ocp, int opcode)
{
	if (ocp == REG_CODE)
	{
		arg->type = T_REG;
		arg->size = 1;
	}
	else if (ocp == IND_CODE)
	{
		arg->type = T_IND;
		arg->size = IND_SIZE;
	}
	else if (ocp == DIR_CODE)
	{
		arg->type = T_DIR;
		if (g_tab[opcode].dir_short)
			arg->size = IND_SIZE;
		else
			arg->size = DIR_SIZE;
	}
}

static size_t					check_param(t_params args[3], char ocp
											, int opcode, int count)
{
	if (!g_tab[opcode].ocp)
	{
		if (g_tab[opcode].dir_short)
		{
			args[0].size = IND_SIZE;
			args[0].type = T_IND;
		}
		else
		{
			args[0].size = DIR_SIZE;
			args[0].type = T_DIR;
		}
		return (1);
	}
	args[1].type = 0;
	args[1].size = 0;
	args[2].type = 0;
	args[2].size = 0;
	which_param(&args[0], (ocp & 0b11000000) >> 6, opcode);
	if (count > 1)
		which_param(&args[1], (ocp & 0b00110000) >> 4, opcode);
	if (count > 2)
		which_param(&args[2], (ocp & 0b00001100) >> 2, opcode);
	return (2);
}

static void						get_param(char *pc, t_params args[3],
															int param_count)
{
	char						*value_ptr;
	int							jump;
	int							size;
	int							i;
	int							j;

	i = 0;
	jump = 0;
	while (i < param_count)
	{
		j = 0;
		size = args[i].size;
		value_ptr = (char *)&args[i].value;
		while (j < size)
		{
			value_ptr[size - (j + 1)] = read_adress_info(pc + jump + j);
			j++;
		}
		jump += args[i].size;
		i++;
	}
}

size_t							analyze_param(t_oper *p, int opcode
											, t_params args[3])
{
	size_t						jump;
	int							param_count;
	int							param_len;

	ft_bzero(args, sizeof(t_params) * 3);
	param_count = g_tab[opcode - 1].hm_params;
	jump = check_param(args, read_adress_info(p->pc + 1),
		opcode - 1, param_count);
	param_len = args[0].size + args[1].size + args[2].size;
	if (param_len > 0)
		get_param((char *)&p->pc[jump], args, param_count);
	return (jump + param_len);
}
