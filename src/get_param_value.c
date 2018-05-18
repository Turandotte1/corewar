/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/04/24 16:40:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_params(t_instruct *inst)
{
	int		i;
	t_op	op;

	i = 0;
	op = g_op_tab[find_op(inst->name)];
	while (i < MAX_ARGS_NUMBER && inst->params[i].init_val)
		i++;
	if (i != op.nb_params)
		return (0);
	i = 0;
	while (i < MAX_ARGS_NUMBER && inst->params[i].init_val)
	{
		if (!(inst->params[i].type & op.arg_type[i]))
			return (0);
		i++;
	}
	return (1);
}

void	param_value(t_param *param, int inst_addr, t_champ *c)
{
	if (param->init_val[0] == LABEL_CHAR || param->init_val[1] == LABEL_CHAR)
		param->value = label_value(param, inst_addr, c);
	else
	{
		if (param->type == T_REG)
		{
			if (!ft_str_is_digits(&param->init_val[1])
			|| ft_atoi(&param->init_val[1]) > REG_NUMBER
			|| ft_atoi(&param->init_val[1]) < 1)
				close_asm(c, "Error: wrong format for reg param\n");
			param->value = ft_atoi(&param->init_val[1]);
		}
		else if (param->type == T_DIR)
		{
			if (!ft_str_is_digits(&param->init_val[1]))
				close_asm(c, "Error: direct param must have only numbers\n");
			param->value = ft_atoi(&param->init_val[1]);
		}
		else if (param->type == T_IND)
		{
			if (!ft_str_is_digits(param->init_val))
				close_asm(c, "Error: indirect param must have only numbers\n");
			param->value = ft_atoi(param->init_val);
		}
	}
}

void	get_param_type(t_champ *c, t_param *param)
{
	if (param->init_val && param->init_val[0] == 'r')
		param->type = T_REG;
	else if (param->init_val && param->init_val[0] == DIRECT_CHAR)
		param->type = T_DIR;
	else if (param->init_val && (param->init_val[0] == '-'
	|| ft_isdigit(param->init_val[0]) || param->init_val[0] == LABEL_CHAR))
		param->type = T_IND;
	else
		close_asm(c, "Error: unknown param type\n");
}

int		get_nb_bytes(t_instruct *instruct)
{
	t_param	*params;
	int		i;
	int		op;
	int		nb_bytes;

	i = 0;
	op = find_op(instruct->name);
	nb_bytes = 0;
	params = instruct->params;
	while ((i < MAX_ARGS_NUMBER) && params[i].type)
	{
		if (params[i].type == T_REG)
			params[i].bytes = 1;
		else if (params[i].type == T_IND)
			params[i].bytes = 2;
		else if (params[i].type == T_DIR)
		{
			if (g_op_tab[op].has_idx)
				params[i].bytes = 2;
			else
				params[i].bytes = 4;
		}
		nb_bytes += params[i++].bytes;
	}
	return (nb_bytes);
}

int		get_param(t_champ *c, t_instruct *inst, char *line)
{
	char	**split;
	int		i;
	int		nb_bytes;

	if (!(split = ft_strsplit(line, SEPARATOR_CHAR)))
		close_asm(c, "Malloc Error\n");
	i = 0;
	nb_bytes = 0;
	while (split[i] && i < MAX_ARGS_NUMBER)
	{
		if (!(inst->params[i].init_val = ft_strdup(ft_strtrim(split[i]))))
			close_asm(c, "Malloc error\n");
		free(split[i]);
		get_param_type(c, &inst->params[i]);
		nb_bytes = get_nb_bytes(inst);
		i++;
	}
	free(split);
	return (nb_bytes);
}
