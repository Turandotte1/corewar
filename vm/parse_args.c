/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:46:22 by mrychkov          #+#    #+#             */
/*   Updated: 2018/07/19 18:46:26 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

static void					give_dispo_name(t_flag *flag, int player)
{
	int					i;
	int					name;
	int					dif;

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

static int					next_nb(char *s)
{
	int							dif;
	long long int				i;

	dif = 0;
	i = 0;
	while (s[i])
		dif += ft_isdigit(s[i++]);
	if (dif != i)
		usage();
	i = ft_atoll(s);
	if (i > 2147483647 || i < 0)
		usage();
	return (i);
}

static int					*is_a_flag(char **argv, int *i, int argc)
{
	int					*ret;
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
	if ((flag == 3 || flag == 1) && (nb = next_nb(argv[*i + 1])) < 0)
		error("value is too big or under 0");
	if (flag == 3 || flag == 1)
		*i += 1;
	if ((ret = (int *)malloc(sizeof(int) * 2)) == NULL)
		error("malloc Error");
	ret[0] = flag;
	ret[1] = nb;
	return (ret);
}

static void					into_struct(int *tab, t_flag *flag)
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

int							flag_or_champ(char **argv,
		t_flag *flags, t_parsing *parsing)
{
	int					i;
	int					fd;
	int					player;
	int					argc;

	i = 0;
	while (argv[i] != NULL)
		++i;
	argc = i;
	i = 1;
	player = 0;
	init_flag(flags, &parsing->code, &parsing->queue, &parsing->names);
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			into_struct(is_a_flag(argv, &i, argc), flags);
		else
		{
			parse_champion(fd, &parsing->queue, &parsing->names,
					concat(&parsing->code, player));
			give_dispo_name(flags, ++player);
		}
		++i;
	}
	return (player);
}
