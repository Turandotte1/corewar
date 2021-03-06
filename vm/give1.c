/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:45:32 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 18:45:51 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

t_norme					concat(t_vec *vec, int player)
{
	t_norme tmp;

	tmp.code = vec;
	tmp.player = player;
	return (tmp);
}

void					give_name(t_flag *f, int name)
{
	int					i;
	int					dif;

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
			ft_printf("Error: same ID for 2 differents champions\n");
			exit(1);
		}
	}
	v_push_int(&f->n, name);
}

void					give_magic_number(t_vec *vec, t_header *head)
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

void					give_size(t_vec *vec, int *i, t_header *head)
{
	while (*(int *)v_get(vec, *i) == 0 && *i < v_size(vec))
		*i += 1;
	head->prog_size = *(int *)v_get(vec, *i);
	if (*i == 138)
	{
		head->prog_size <<= 8;
		*i += 1;
		head->prog_size += *(int *)v_get(vec, *i);
	}
	*i += 1;
	if (head->prog_size > CHAMP_MAX_SIZE)
		error("Champion is too big");
}

void					give_comment(t_vec *vec, int *i, t_header *head)
{
	int y;

	y = 0;
	while (*(int *)v_get(vec, *i) != 0 && *i < v_size(vec))
	{
		head->comment[y++] = *(int *)v_get(vec, *i);
		*i += 1;
		if (y > COMMENT_LENGTH)
			error("Comment is too long");
	}
	head->comment[y] = '\0';
}
