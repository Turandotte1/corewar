/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:03:40 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/10 18:53:38 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void		into_code(t_vec *code, t_vec *vec, header_t *head)
{
	int		i;
	char	*tmp;

	i = 2192;
	if ((tmp = (char *)malloc(sizeof(char) * (head->prog_size + 1))) == NULL)
		error("Malloc Error");
	while (i < v_size(vec))
	{
		tmp[i - 2192] = *(char *)v_get(vec, i);
		++i;
	}
	tmp[i] = '\0';
	v_push(code, tmp);
}

t_vec		read_ins(int fd)
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

void		give_magic_number(t_vec *vec, header_t *head)
{
	if (v_size(vec) < 7)
		error("Bad Header");
	if (*(int *)v_get(vec, 1) != 0xea)
		error("Bad Header");
	if (*(int *)v_get(vec, 2) != 0x83)
		error("Bad Header");
	if (*(int *)v_get(vec, 3) != 0xf3)
		error("Bad Header");
	head->magic = 0xea83f3;
}

void		give_name(t_flag *f, int name)
{
	int				i;
	int				dif;

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

void		filter_vec(t_vec *vec, t_vec *code)
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
	v_del(vec);
}

void		pars(int fd, t_vec *queue, t_vec *names, t_vec *code)
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
	filter_vec(&vec, code);
}
