/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:07:10 by mipham            #+#    #+#             */
/*   Updated: 2018/04/24 16:40:37 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	parse_file(char *content, t_champ *champ)
{
	content = parse_header(content, champ);
	content = skip_comment_and_whitespace(content);
	parse_body(content, champ);
	if (!champ->instructs && !champ->labels)
		close_asm(champ, "Error: no instruction or label\n");
}

char	*parse_header(char *content, t_champ *champ)
{
	content = skip_comment_and_whitespace(content);
	champ->name = get_name_or_comment(champ, &content, NAME_CMD_STRING);
	champ->comment = get_name_or_comment(champ, &content, COMMENT_CMD_STRING);
	content = skip_comment_and_whitespace(content);
	if (!champ->name || !champ->comment)
		close_asm(champ, "Error: champ needs to have a name and a comment\n");
	if (ft_strlen(champ->name) >= PROG_NAME_LENGTH)
		close_asm(champ, "Error: champion's name is too long\n");
	if (ft_strlen(champ->comment) >= COMMENT_LENGTH)
		close_asm(champ, "Error: champion's comment is too long\n");
	return (content);
}
