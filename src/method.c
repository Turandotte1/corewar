//
// Created by Minh PHAM on 4/20/18.
//
#include "../includes/asm.h"

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
