#include "../includes/asm.h"

void	parse_file(char *content, t_champ *champ)
{
	content = parse_header(content, champ);
	content = skip_comment_and_whitespace(content);
	parse_body(content, champ);
	if (!champ->instructs && !champ->labels)
		close_asm(champ, "Error: no instruction or label\n");
}

char	*get_name_or_comment(t_champ *c, char **content, char *str)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	*content = skip_comment_and_whitespace((*content));
	if (ft_strncmp(*content, str, ft_strlen(str)) == 0)
	{
		*content = ft_strchr(*content, '"') + 1;
		while ((*content)[i] && (*content)[i] != '"')
			i++;
		if (!(result = ft_strndup(*content, i)))
			close_asm(c, "Malloc error\n");
		*content = ft_point_to_next_line(&(*content)[i]);
	}
	return (result);
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
