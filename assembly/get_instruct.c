/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/07/18 14:47:54 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/asm.h"

t_instruct	*new_instruct(void)
{
	t_instruct	*instruct;

	if (!(instruct = malloc(sizeof(t_instruct))))
		return (NULL);
	ft_memset(instruct, 0, sizeof(*instruct));
	return (instruct);
}

void		add_instruct_end(t_champ *champ, t_instruct *instruct)
{
	t_instruct	*tmp;

	if (champ->instructs == NULL)
	{
		champ->instructs = instruct;
		return ;
	}
	tmp = champ->instructs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = instruct;
	instruct->next = NULL;
}

int			get_instruct(t_champ *champ, char *line, int nb_bytes)
{
	t_instruct	*instruct;
	int			i;
	int			has_opc;

	i = 0;
	has_opc = 0;
	line = ft_skip_whitespace(save_label_name(champ, line, nb_bytes));
	while (line[i] && !ft_strchr(" \t-", line[i]) && line[i] != DIRECT_CHAR
			&& line[i] != LABEL_CHAR && !ft_isdigit(line[i]))
		i++;
	if (line[i] != '\0' && line[i] != '\n')
	{
		instruct = new_instruct();
		if (!(instruct->name = ft_strndup(line, i)))
			close_asm(champ, "Malloc error\n");
		if (!find_op(instruct->name))
			close_asm(champ, "Error: bad char in instruction or label\n");
		instruct->opcode = find_op(instruct->name);
		line = &line[i];
		instruct->address = nb_bytes;
		has_opc = g_op_tab[instruct->opcode].has_opc;
		nb_bytes += 1 + has_opc + get_param(champ, instruct, line);
		add_instruct_end(champ, instruct);
	}
	return (nb_bytes);
}

void		free_instructs(t_instruct *instructs)
{
	t_instruct	*tmp_instruct;
	int			i;

	while (instructs)
	{
		tmp_instruct = instructs;
		instructs = instructs->next;
		i = 0;
		while (i < MAX_ARGS_NUMBER)
		{
			free(tmp_instruct->params[i].raw_value);
			i++;
		}
		free(tmp_instruct->name);
		free(tmp_instruct);
	}
	free(instructs);
}

int			params_size(t_instruct *instr)
{
	int	i;
	int res;

	res = 0;
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		res += instr->params[i].nb_bytes;
		++i;
	}
	return (res);
}
