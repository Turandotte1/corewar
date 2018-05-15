/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:45:12 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/15 20:45:14 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	give_dispo_name(t_flag *flag, int player)
{
	int i;
	int name;
	int dif;

	name = 1;
	i = 0;
	if (player == v_size(&flag->n))
		return ;
	if (v_raw(&flag->n) == NULL)
	{
		flag->n = v_new(sizeof(int));
		v_push_int(&flag->n, 1);
		return ;
	}
	while (i < v_size(&flag->n))
	{
		dif = *(int *)v_get(&flag->n, i);
		if (dif >= name)
			name = dif + 1;
		++i;
	}
	v_push_int(&flag->n, name);
}

t_vec		v_to_hexa(t_vec *vec)
{
	int		i;
	char	c;
	int		r;
	t_vec	tmp;

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

int			get_next_position(int noc, int ci)
{
		return (((MEM_SIZE * 3) - noc) / noc * ci + (ci + 1));
}

char		*vec_to_char(t_vec *map)
{
	char *arena;
	int i;

	i = 0;
	if ((arena = (char *)malloc(sizeof(char) * (v_size(map) + 1))) == NULL)
		error("Malloc error");
	while (i < v_size(map))
	{
		arena[i] = *(char *)v_get(map, i);
		++i;
	}
	arena[i] = '\0';
	return (arena);
}

void		complete_vm(t_vm *vm, t_vec *map, t_flag *flag, t_vec *code)
{
	int i;

	i = 0;
	vm->arena = vec_to_char(map);
	vm->n = v_copy(&flag->n);
	vm->v = flag->v;
	vm->dump = flag->dump;
	vm->dump_nb = flag->dump_nb;
	v_del(&flag->n);
	v_del(map);
	while (i < v_size(code))
	{
		v_del((t_vec *)v_get(code, i));
		++i;
	}
	v_del(code);
}

void		into_vm(t_vm *vm, t_flag *flag, t_vec *code)
{
	int i;
	t_vec map;
	t_vec tmp;
	int y;
	char *lala;

	map = v_new(sizeof(char));
	i = 0;
	while (i < v_size(code))
	{
		tmp = *(t_vec *)v_get(code, i++);
		y = 0;
		while (y < v_size(&tmp))
		{
			lala = ft_itoa_base((*(int *)v_get(&tmp, y++) & 0xff), 16, 'x');
			if (ft_strlen(lala) == 1)
				v_push(&map, "0");
			v_append_raw(&map, lala, ft_strlen(lala));
			v_push(&map, " ");
			free(lala);
		}
		while (v_size(&map) + 3 < get_next_position(v_size(code), i))
			v_append_raw(&map, "00 ", 3);
	}
	complete_vm(vm, &map, flag, code);
}
