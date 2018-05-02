/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:14:56 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/27 19:26:24 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

t_vec		read_ins(int fd)
{
	int			ret;
	char		tmp[BUFF_SIZE + 1];
	t_vec		vec;

	vec = v_new(sizeof(char));
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
		v_append_raw(&vec, tmp, ret);
	vec = v_to_hexa(&vec);
	if (ret == -1)
		error("imcomplet Read");
	return (vec);
}

void		give_magic_number(t_vec *vec, header_t *head)
{
	if (v_size(vec) < 7)
		error("Magic number is not the good one");
	if (*(int *)v_get(vec, 1) != 0xea)
		error("Magic number is not the good one");
	if (*(int *)v_get(vec, 2) != 0x83)
		error("Magic number is not the good one");
	if (*(int *)v_get(vec, 3) != 0xf3)
		error("Magic number is not the good one");
	head->magic = 0xea83f3;
}

void					give_name(t_flag *f, int name)
{
	int 				i;
	int 				dif;

	i = 0;
	if (v_size(&f->n) == 0)
	{
		v_push_int(&f->n, name);
		return ;
	}
	while (i < v_size(&f->n))
	{
		dif = *(int *)v_get(&f->n, i++);
		if (name == dif)
		{
			printf("Error: same ID for 2 differents champions\n");
			exit(1);
		}
	}
	v_push_int(&f->n, name);
}

void					pars(int fd, t_vec *queue, t_vec *names)
{
	t_vec		vec;
	int			i;
	header_t	head;

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
}
