/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_g_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:11:15 by glegendr          #+#    #+#             */
/*   Updated: 2018/07/19 16:16:23 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

t_vm							g_vm;

char				*vec_to_char(t_vec *map)
{
	char			*arena;
	int				i;

	i = 0;
	if ((arena = (char *)malloc(sizeof(char) * (v_size(map) * 2 + 1))) == NULL)
		error("malloc error");
	while (i < v_size(map))
	{
		arena[i] = *(char *)v_get(map, i);
		++i;
	}
	arena[i] = '\0';
	return (arena);
}

static void			complete_vm(t_vec *map, t_flag *flag, t_vec *code)
{
	int				i;

	i = 0;
	g_vm.arena = vec_to_char(map);
	g_vm.v = flag->v;
	g_vm.dump = flag->dump;
	g_vm.dump_nb = flag->dump_nb;
	v_del(&flag->n);
	v_del(map);
	while (i < v_size(code))
	{
		v_del((t_vec *)v_get(code, i));
		++i;
	}
	v_del(code);
}

static int			get_next_position(int player, int ci)
{
	return (MEM_SIZE / player * ci);
}

void				into_vm(t_flag *flag, t_vec *code)
{
	int				i;
	int				y;
	t_vec			map;
	t_vec			tmp;

	map = v_new(sizeof(char));
	i = 0;
	while (i < v_size(code))
	{
		g_vm.champ[i].position = get_next_position(v_size(code), i);
		g_vm.champ[i].champ_id = *(int *)v_get(&flag->n, i);
		tmp = *(t_vec *)v_get(code, i++);
		y = 0;
		while (y < v_size(&tmp))
		{
			v_push_int(&map, *(char *)v_get(&tmp, y));
			++y;
		}
		while (v_size(&map) < get_next_position(v_size(code), i))
			v_push_int(&map, (char)0);
	}
	complete_vm(&map, flag, code);
}
