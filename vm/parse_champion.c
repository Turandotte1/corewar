/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:46:37 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 18:46:39 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

static t_vec				v_to_hexa(t_vec *vec)
{
	int						i;
	char					c;
	int						r;
	t_vec					tmp;

	tmp = v_new(sizeof(int));
	i = 0;
	while (i < v_size(vec))
	{
		c = *(int *)v_get(vec, i);
		r = (c & 0xff);
		v_push_int(&tmp, r);
		++i;
	}
	v_del(vec);
	return (tmp);
}

static void					filter_vec(t_vec *vec, t_vec *code,
		int player)
{
	t_vec	tmp;
	int		i;

	i = 2192;
	tmp = v_new(sizeof(int));
	if (v_size(vec) < i)
		return ;
	while (i < v_size(vec))
	{
		v_push_int(&tmp, *(char *)v_get(vec, i));
		++i;
	}
	v_push(code, &tmp);
	g_vm.champ[player].ch = (char *)malloc(sizeof(char) * (v_size(&tmp) + 1));
	ft_memcpy(g_vm.champ[player].ch, v_raw(&tmp), v_size(&tmp));
	g_vm.champ[player].len = v_size(&tmp);
	v_del(vec);
}

static t_vec				read_ins(int fd)
{
	int			ret;
	char		tmp[BUFF_SIZE + 1];
	t_vec		vec;

	vec = v_new(sizeof(char));
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		v_append_raw(&vec, tmp, ret);
		if (v_size(&vec) > 15000)
			error("The size is to big to be a champion");
	}
	vec = v_to_hexa(&vec);
	if (ret == -1)
		error("imcomplet Read");
	return (vec);
}

void						parse_champion(int fd, t_vec *queue, t_vec *names,
										t_norme norme)
{
	int						i;
	t_vec					vec;
	t_header				head;

	vec = read_ins(fd);
	give_magic_number(&vec, &head);
	i = 4;
	while (ft_isprint(*(int *)v_get(&vec, i)) && i < v_size(&vec))
	{
		head.prog_name[i - 4] = *(int *)v_get(&vec, i);
		++i;
		if (i - 4 > 128)
			error("name is too long");
	}
	head.prog_name[i - 4] = '\0';
	give_size(&vec, &i, &head);
	give_comment(&vec, &i, &head);
	while (*(int *)v_get(&vec, i) == 0 && i < v_size(&vec))
		++i;
	if ((int)(i + head.prog_size) != v_size(&vec) || i != 2192)
		error("size is too big");
	give_actions(&vec, queue);
	v_push(names, &head);
	g_vm.champ[norme.player].head = head;
	filter_vec(&vec, norme.code, norme.player);
}
