/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:14:56 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/03 19:56:01 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int						main(int argc, char **argv)
{
	t_vm				vm;
	t_flag				flag;

	if (argc == 1)
		usage();
	ft_bzero(&vm, sizeof(t_vm));
	parse_it(&vm, flag, argc, argv);
//	run_it(&vm);
	//on n'oublie de rien free !!
	return (0);
}
