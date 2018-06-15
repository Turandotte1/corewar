/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:14:56 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/29 22:36:15 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						main(int argc, char **argv)
{
	t_vm				vm;
	t_flag				flag;

	if (argc == 1)
		usage();
	ft_bzero(&vm, sizeof(t_vm));
	ft_bzero(&flag, sizeof(t_flag));
	vm.champ = malloc(sizeof(t_champion) * argc);
	parse_args(&vm, flag, argc, argv);
//	print_memory(vm.arena, MEM_SIZE);
	war_start(&vm);
	free(vm.arena);
	v_del(&vm.n);
	return (0);
}
