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

#include "tmp.h"

int(*g_tab_fonctions[0x10])(t_act *act, t_vec *vec, int i) =
{f_live, f_ld, f_st, f_add, f_sub, f_and, f_and, f_and, f_zjmp,
	f_ldi, f_sti, f_fork, f_ld, f_ldi, f_fork, f_aff};

int			error(char *s)
{
	if (!ft_strcmp(s, ""))
	{
		printf("Error\n");
		exit(1);
		return (0);
	}
	printf("Error: %s\n", s);
	exit(1);
	return (0);
}

void		usage(void)
{
	printf("Usage: ./corewar [-v | -n N | -dump N] <champion1.cor> <...>\n");
	printf("----------------------------flags---------------------------\n");
	printf("    -v		Met en place le visualisateur\n");
	printf("    -n N	Fixe le numero du prochain joueur\n");
	printf("    -dump N	Raccourcie la partie a N cycles\n");
	printf("------------------------------------------------------------\n");
	exit(1);
}

int			next_nb(char *s)
{
	int dif;
	int i;

	dif = 0;
	i = 0;
	while (s[i])
		dif += ft_isdigit(s[i++]);
	if (dif != i)
		usage();
	return (ft_atoi(s));
}

void		give_name(t_flag *f, int name)
{
	int i;
	int dif;

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

void		into_struct(int *tab, t_flag *flag)
{
	int f;
	int nb;

	if (v_raw(&flag->n) == NULL)
		flag->n = v_new(sizeof(int));
	f = tab[0];
	nb = tab[1];
	free(tab);
	if ((f == 2 && flag->v == 1) || (f == 3 && flag->dump == 1))
		usage();
	if (f == 2)
		flag->v = 1;
	else if (f == 3)
	{
		flag->dump = 1;
		flag->dump_nb = nb;
	}
	else
		give_name(flag, nb);
}

int			*make_ret(int flag, int nb)
{
	int *ret ;

	if ((ret = (int *)malloc(sizeof(int) * 2)) == NULL)
		error("malloc Error");
	ret[0] = flag;
	ret[1] = nb;
	return (ret);
}

int			*is_a_flag(char **argv, int *i, int argc)
{
	int flag;
	int nb;

	nb = 0;
	if (ft_strcmp(argv[*i], "-n") && ft_strcmp(argv[*i], "-v") &&
			ft_strcmp(argv[*i], "-dump"))
		usage();
	if (!ft_strcmp(argv[*i], "-n"))
		flag = 1;
	else if (!ft_strcmp(argv[*i], "-v"))
		flag = 2;
	else
		flag = 3;
	if (*i == argc - 1 && (flag == 3 || flag == 1))
		usage();
	if (flag == 3 || flag == 1)
	{
		if ((nb = next_nb(argv[*i + 1])) < 0)
			error("value is too big or under 0");
		*i += 1;
	}
	return (make_ret(flag, nb));
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

t_act		ini_struct(void)
{
	t_act act;

	act.act = 0;
	act.f_p = -1;
	act.s_p = -1;
	act.t_p = -1;
	return (act);
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

int			give_parameters(t_act *act, t_vec *vec, int i)
{
	if (act->act > 0x10 || act->act < 1)
		return (error("Unfounded action"));
	else
		return (g_tab_fonctions[act->act - 1](act, vec, i));
}

void		give_size(t_vec *vec, int *i, header_t *head)
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
		error("Size is over 9000");
}

void		give_comment(t_vec *vec, int *i, header_t *head)
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

void		give_actions(t_vec *vec, t_vec *queue)
{
	t_vec	tmp;
	t_act	act;
	int		i;

	i = 2192;
	tmp = v_new(sizeof(t_act));
	while (i < v_size(vec))
	{
		act = ini_struct();
		act.act = *(int *)v_get(vec, i++);
		i = give_parameters(&act, vec, i);
		v_push(&tmp, &act);
	}
	v_push(queue, &tmp);
}

void		pars(int fd, t_vec *queue, t_vec *names)
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

void		give_dispo_name(t_flag *flag, int player)
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

void		print(int i, t_vec queue, t_vec names, t_flag flags)
{
	t_vec	tmp;
	int y;

	while (i < v_size(&queue))
	{
		header_t tmp2;
		tmp2 = *(header_t *)v_get(&names, i);
		printf("\n---------------%i---------------\n", i + 1);
		printf("name: %s   ID: %i\n", tmp2.prog_name, *(int *)v_get(&flags.n, i));
		printf("Comment: %s\n", tmp2.comment);
		printf("size: %i   magic number: %x\n", tmp2.prog_size, tmp2.magic);
		tmp = *(t_vec *)v_get(&queue, i++);
		printf("actions:\n");
		y = 0;
		while (y < v_size(&tmp))
		{
			t_act act = *(t_act *)v_get(&tmp, y++);
			printf("act %x: %i %i %i\n", act.act, act.f_p, act.s_p, act.t_p);
		}
	}
	printf("Flags: ");
	if (flags.v == 1)
		printf("-v ");
	if (flags.dump == 1)
		printf("-dump (%i)", flags.dump_nb);
	if (flags.v == 0 && flags.dump == 0)
		printf("Null\n");
}

int			main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_vec	queue;
	t_vec	names;
	int		player;
	t_flag	flags;

	flags.n = v_new(sizeof(int));
	queue = v_new(sizeof(t_vec));
	names = v_new(sizeof(header_t));
	i = 1;
	player = 0;
	if (argc == 1)
		usage();
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			into_struct(is_a_flag(argv, &i, argc), &flags);
		else
		{
			pars(fd, &queue, &names);
			++player;
			give_dispo_name(&flags, player);
		}
		++i;
	}
	if (player == 0 || v_size(&flags.n) != player)
		usage();
	print(0, queue, names, flags);
}
