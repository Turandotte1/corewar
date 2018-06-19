/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:02:23 by mipham            #+#    #+#             */
/*   Updated: 2018/06/12 11:02:26 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/asm.h"

int		find_op(char *name)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (ft_strcmp(g_op_tab[i].name, name) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*skip_comment_and_whitespace(char *str)
{
	str = ft_strtrim_both(str);
    if(str == NULL)
        return(0);
	while (str[0] == COMMENT_CHAR || str[0] == '\n' || str[0] == ';')
		str = ft_point_to_next_line(str);
	return (str);
}

char	*trim_comment(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR || line[i] == ';')
			line[i] = '\0';
		i++;
	}
	return (line);
}

char	*get_name_or_comment(t_champ *c, char **content, char *str)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
    if (*content == NULL)
        return (0);
	*content = skip_comment_and_whitespace(*content);
    if (ft_strncmp(*content, str, ft_strlen(str)) == 0)
	{
        *content = ft_strchr(*content, '"');
        if (*content == NULL)
            return (0);
        else
            *content = *content + 1;
        while ((*content)[i] && (*content)[i] != '"')
			i++;
		if (!(result = ft_strndup(*content, i)))
			close_asm(c, "Malloc error\n");
		*content = ft_point_to_next_line(&(*content)[i]);
	}
	return (result);
}