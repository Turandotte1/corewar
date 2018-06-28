/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:14:56 by glegendr          #+#    #+#             */
/*   Updated: 2018/06/18 20:39:38 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/includes/vm.h"

void						convert_endian(char *dest, char *src, 
															size_t type_len)
{
	int						i;

	i = type_len - 1;
	while (i >= 0)
	{
		dest[i] = src[type_len - (i + 1)];
		i--;
	}
}

void						war_start(t_vm *vm)
{
	int						how_many_players;
	int						position;
	int						i;
	t_champion 				*champ;

	how_many_players = vm->champs;
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < how_many_players)
	{
		champ = &vm->champ[i];
		position = champ->position;
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", 
			champ->champ_id, champ->head.prog_size, champ->head.prog_name, champ->head.comment);
		make_process(vm, &vm->arena[position], NULL);
		champ->champ_id = -champ->champ_id;
		champ->id = i;
		convert_endian((char*)&vm->ops[i].r[0], (char *)&champ->champ_id, REG_SIZE);
		i++;
	}
	players_are_ready(vm);
}

void						del_queue(t_vec *vec, t_vec *names)
{
	int					i;

	i = 0;
	while (i < v_size(vec))
	{
		v_del((t_vec *)v_get(vec, i));
		++i;
	}
	v_del(vec);
	v_del(names);
}

void						parse_args(t_vm *vm, t_flag flags, char **argv)
{
	int						player;
	t_parsing				parsing;

	ft_bzero(&parsing, sizeof(t_parsing));
	player = flag_or_champ(vm, argv, &flags, &parsing);
	if (player == 0 || v_size(&flags.n) != player)
		usage();
	if (player > 4)
		error("too many champions");
	vm->champs = player;
	into_vm(vm, &flags, &parsing.code);
	del_queue(&parsing.queue, &parsing.names);
}

int							main(int argc, char **argv)
{
	t_vm					vm;
	t_flag					flag;

	if (argc == 1)
		usage();
	ft_bzero(&vm, sizeof(t_vm));
	ft_bzero(&flag, sizeof(t_flag));
	vm.champ = malloc(sizeof(t_champion) * argc - 1);
	parse_args(&vm, flag, argv);
	war_start(&vm);
	free(vm.arena);
	return (0);
}
