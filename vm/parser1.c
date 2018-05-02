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

int							next_nb(char *s)
{
	int 					dif;
	int 					i;

	dif = 0;
	i = 0;
	while (s[i])
		dif += ft_isdigit(s[i++]);
	if (dif != i)
		usage();
	return (ft_atoi(s));
}

int							*make_ret(int flag, int nb)
{
	int 					*ret ;

	if ((ret = (int *)malloc(sizeof(int) * 2)) == NULL)
		error("malloc Error");
	ret[0] = flag;
	ret[1] = nb;
	return (ret);
}

int							*is_a_flag(char **argv, int *i, int argc)
{
	int 					flag;
	int 					nb;

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

void						into_struct(int *tab, t_flag *flag)
{
	int 					f;
	int 					nb;

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

int 						parse_it(t_vm *vm, int argc, char **argv)
{
	int						i;
	int						fd;
	int						player;
	t_vec					queue;
	t_vec					names;
	
	flags.n = v_new(sizeof(int));
	queue = v_new(sizeof(t_vec));
	names = v_new(sizeof(header_t));
	player = 0;
	while ((i = 1) && i < argc)
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