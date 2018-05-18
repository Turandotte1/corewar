/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/04/24 16:40:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*save_label_name(t_champ *champ, char *line, int nb_bytes)
{
	int		i;
	int		j;
	t_label	*label;

	i = 0;
	j = ft_strchr_i(line, LABEL_CHAR);
	while (line[i] && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		if (i == (j - 1) && ft_strchr(LABEL_CHARS, line[i]))
		{
			label = new_label();
			if (!(label->name = ft_strndup(line, j)))
				close_asm(champ, "Malloc error\n");
			label->address = nb_bytes;
			if (champ)
				add_label_end(champ, label);
			line = line + j + 1;
			break ;
		}
		i++;
	}
	return (line);
}

void	parse_params(t_champ *champ)
{
	t_instruct	*inst;
	int			i;

	inst = champ->instructs;
	while (inst)
	{
		i = 0;
		while (i < MAX_ARGS_NUMBER && inst->params[i].init_val)
			param_value(&inst->params[i++], inst->address, champ);
		if (!(check_params(inst)))
			close_asm(champ, "Error: wrong parameters for instruction\n");
		inst = inst->next;
	}
}

void	parse_body(char *content, t_champ *champ)
{
	char		*line;
	int			nb_bytes;

	nb_bytes = 0;
	while (content[0])
	{
		content = skip_comment_and_whitespace(content);
		line = trim_comment(ft_cut_first_line(content));
		if (ft_strchr(line, '.'))
			close_asm(champ, "Error: unknown command\n");
		content = ft_point_to_next_line(content);
		nb_bytes = get_instruct(champ, line, nb_bytes);
//		if (nb_bytes > CHAMP_MAX_SIZE)
//			close_asm(champ, "Error: champ is too large\n");
		free(line);
	}
	parse_params(champ);
}
