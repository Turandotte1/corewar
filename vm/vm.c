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

/*
** Things to do:
** Lier visu au bon endroit, ajouter cycle ncurse
** ajouter memory dump dans someone_is_alive in run.c
*/

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

void						war_start(t_vm *vm)
{
	int						how_many_players;
	int						position;
	int						i;

	how_many_players = vm->champs;
	i = 0;
	while (how_many_players)
	{
		position = vm->champ[i++].position;
		make_process(vm, &vm->arena[position], NULL);
		--how_many_players;
	}
	vm->cycle.to_die = CYCLE_TO_DIE;
	vm->cycle.check = CYCLE_TO_DIE;
	vm->cycle.cur = 0;
	if (vm->v)
		printf("visu mode\n");
	else
	{
		while (someone_is_alive(vm))
			;
	}
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
	vm.champ = malloc(sizeof(t_champion) * argc);
	parse_args(&vm, flag, argv);
//	print_memory(vm.arena, MEM_SIZE);
	war_start(&vm);
	free(vm.arena);
	return (0);
}
