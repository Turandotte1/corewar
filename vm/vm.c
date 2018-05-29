/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:14:56 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/15 20:14:56 by glegendr         ###   ########.fr       */
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
	parse_args(&vm, flag, argc, argv);
	war_start(&vm);

//	printf("%s\n", vm.arena);
	//on n'oublie de rien free !!
	free(vm.arena);
	v_del(&vm.n);
	return (0);
}