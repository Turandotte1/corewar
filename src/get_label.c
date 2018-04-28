
//
// Created by Minh PHAM on 4/20/18.
//
#include "../includes/asm.h"

t_label	*new_label(void)
{
	t_label	*label;

	if (!(label = malloc(sizeof(t_label))))
		return (NULL);
	ft_memset(label, 0, sizeof(*label));
	return (label);
}

int		get_label_addr(t_label *labels, char *name)
{
	t_label	*tmp;

	tmp = labels;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp->address);
		tmp = tmp->next;
	}
	return (-1);
}

int		label_value(t_param *param, int inst_addr, t_champ *c)
{
	char	*label;
	int		res;

	res = 0;
	if (!(label = ft_strdup(ft_strchr(param->raw_value, LABEL_CHAR) + 1))
	|| get_label_addr(c->labels, label) == -1)
		close_asm(c, "Error: non existent label\n");
	if (inst_addr > get_label_addr(c->labels, label))
		res = get_label_addr(c->labels, label) - inst_addr;
	else
		res = -1 * (inst_addr - get_label_addr(c->labels, label));
	free(label);
	return (res);
}

void	add_label_end(t_champ *champ, t_label *label)
{
	t_label	*tmp;

	if (champ->labels == NULL)
	{
		champ->labels = label;
		return ;
	}
	tmp = champ->labels;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = label;
	label->next = NULL;
}

void	free_labels(t_label *labels)
{
	t_label	*tmp_label;

	while (labels)
	{
		tmp_label = labels;
		labels = labels->next;
		free(tmp_label->name);
		free(tmp_label);
	}
	free(labels);
}
