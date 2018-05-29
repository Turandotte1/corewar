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

#include "vm.h"

static int				next_nb(char *s)
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

static int				*is_a_flag(char **argv, int *i, int argc)
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
	if (flag == 3 || flag == 1)
		if ((nb = next_nb(argv[*i + 1])) < 0)
			error("value is too big or under 0");
		*i += 1;
	if ((ret = (int *)malloc(sizeof(int) * 2)) == NULL)
		error("malloc Error");
	ret[0] = flag;
	ret[1] = nb;
	return (ret);
}

static void				into_struct(int *tab, t_flag *flag)
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

static int				flag_or_champ(t_vm *vm, int argc, char **argv, t_flag *flags, t_parsing *parsing)
{
	int					i;
	int					fd;
	int 				player;
	
	i = 1;
	player = 0;
	init_flag(flags, &parsing->code, &parsing->queue, &parsing->names);
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			into_struct(is_a_flag(argv, &i, argc), flags);
		else
		{
			vm->champ[player].ch = vec_to_char(&parsing->code);
			printf(" CHAMP in args %s\n", vm->champ[player].ch);
			vm->champ[player].len = v_size(&parsing->code);
			parse_champion(fd, &parsing->queue, &parsing->names, &parsing->code);
			give_dispo_name(flags, ++player);
		}
		++i;
	}
	return (player);
}

void						parse_args(t_vm *vm, t_flag flags, int argc, char **argv)
{
	int 					i;
	int						player;
	t_parsing				parsing;
	t_oper 					*ops;
	
	i = 0;
	ft_bzero(&parsing, sizeof(t_parsing));
	player = flag_or_champ(vm, argc, argv, &flags, &parsing);
	if (player == 0 || v_size(&flags.n) != player)
		usage();
	if (player > 4)
		error("too many champions");
	vm->ops = (t_oper *)malloc(sizeof(t_oper) * player);
	vm->champ = (t_champion *)malloc(sizeof(t_champion) * player);
	vm->champs = player;
	while (i < player)
	{
		ops = &vm->ops[i++];
		ft_bzero(ops, sizeof(t_oper));
	}
	into_vm(vm, &flags, &parsing.code);
	del_queue(&parsing.queue, &parsing.names);
}