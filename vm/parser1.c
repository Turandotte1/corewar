/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:03:47 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/15 20:31:36 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int			next_nb(char *s)
{
	int					dif;
	int					i;

	dif = 0;
	i = 0;
	while (s[i])
		dif += ft_isdigit(s[i++]);
	if (dif != i)
		usage();
	return (ft_atoi(s));
}

int			*make_ret(int flag, int nb)
{
	int					*ret;

	if ((ret = (int *)malloc(sizeof(int) * 2)) == NULL)
		error("malloc Error");
	ret[0] = flag;
	ret[1] = nb;
	return (ret);
}

int			*is_a_flag(char **argv, int *i, int argc)
{
	int					flag;
	int					nb;

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

void		into_struct(int *tab, t_flag *flag)
{
	int					f;
	int					nb;

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

void		ini_flag(t_flag *flag, t_vec *code,
		t_vec *queue, t_vec *names)
{
	flag->v = 0;
	flag->dump = -1;
	flag->dump_nb = -1;
	flag->n = v_new(sizeof(int));
	*code = v_new(sizeof(t_vec));
	*queue = v_new(sizeof(t_vec));
	*names = v_new(sizeof(header_t));
}

void		del_queue(t_vec *vec, t_vec *names)
{
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		v_del((t_vec *)v_get(vec, i));
		++i;
	}
	v_del(vec);
	v_del(names);
}

void		parse_it(t_vm *vm,
		t_flag flags, int argc, char **argv)
{
	int						i;
	int						fd;
	int						player;
	t_vec					queue;
	t_vec					names;
	t_vec					code;

	ini_flag(&flags, &code, &queue, &names);
	player = 0;
	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			into_struct(is_a_flag(argv, &i, argc), &flags);
		else
		{
			pars(fd, &queue, &names, &code);
			give_dispo_name(&flags, ++player);
		}
		++i;
	}
	if (player == 0 || v_size(&flags.n) != player)
		usage();
	if (player > 4)
		error("too many champions");
	into_vm(vm, &flags, &code);
	del_queue(&queue, &names);
}
